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

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    if(N/A+(N%A>0)>B || N<A+B-1){
        cout << -1 << endl;
        return 0;
    }else if(B==1){
        for(int i=0; i<N; i++){
            if(i!=0){
                cout << ' ';
            }
            cout << i+1;
        }
        cout << endl;
        return 0;
    }

    vector<int> ans(N,0);
    for(int i=0; i<A; i++){
        ans[i]=N-A+1+i;
    }

    int fact = (N-A)/(B-1);
    int r = (N-A)%(B-1);
    int k=A;
    int c=N-A;
    for(int j=1; k<N; j++){
        int h=fact;
        if(r>0){
            h++;
        }
        c-=h;
        for(int i=1; i<=h; i++){
            ans[k]=c+i;
            k++;
        }
        r--;
    }
    cout_vec(ans);
}