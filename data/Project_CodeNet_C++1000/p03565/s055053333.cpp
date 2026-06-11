#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    string S, T;
    cin >> S >> T;
    int N,M;
    N=S.size();
    M=T.size();

    int pnt=-1;
    for(int i=N-M; i>=0; i--){
        bool flag=true;
        for(int j=0; j<M; j++){
            if(S[i+j]=='?'){
                continue;
            }else if(S[i+j]!=T[j]){
                flag=false;
                break;
            }
        }
        if(flag){
            pnt=i;
            break;
        }
    }
    if(pnt==-1){
        cout << "UNRESTORABLE" << endl;
    }else{
        for(int i=0; i<N; i++){
            if(S[i]=='?'){
                S[i]='a';
            }
        }
        for(int i=0; i<M; i++){
            S[pnt+i]=T[i];
        }
        cout << S << endl;
    }
}