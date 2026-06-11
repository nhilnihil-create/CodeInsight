#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll N; cin >> N; 
    vector<ll> A(N); for(int i = 0; i < N; i++) cin >> A[i];
    vector<ll> DP(N+2);
    for(int i = N-1; i >= 0; i--){
        ll x = A[i];
        DP[x] = DP[x+1]+1;
    }
    ll Max = 1;
    for(int i = 1; i < N+1; i++) Max = max(Max, DP[i]);
    cout << N-Max << endl;






}