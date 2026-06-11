#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int res = INT_MAX;
    int W[N+1]={},B[N+1]={};
    rep(i,N){
        if(S[i] == '#')B[i+1]++;
        else W[i+1]++;
        B[i+1] += B[i];
        W[i+1] += W[i];
    }
    rep(i,N+1){
        res = min(res,B[i] + (W[N] - W[i]));
    }
    cout << res << endl;
    
    return 0;
}