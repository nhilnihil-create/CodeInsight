#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;


int main(){
    ll N; cin >> N;
    vec h(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> h[i];
    }

    vec dp(N,1e+15);    
    dp[0] = 0;

    for (ll i = 0; i < N; i++)
    {
        if( i+1 < N )
        dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));        
        if( i+2 < N )
        dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
    }
    cout << dp[N-1] << endl;
    


}