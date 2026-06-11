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

using namespace std;

long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<int> C(N,0);
    for(int i=0; i<N; i++){
        cin >> C[i];
    }

    vector<long long> pattern(N,0);
    pattern[0]=1;
    vector<int> prev(200000+1,-1);
    for(int i=0; i<N; i++){
        int c=C[i];
        if(prev[c]!=-1 && prev[c]!=i-1){
            pattern[i]=(pattern[prev[c]]+pattern[i-1])%MOD;
        }else if(i>0){
            pattern[i]=pattern[i-1];
        }
        prev[c]=i;
    }
    cout << pattern[N-1] << endl;
}