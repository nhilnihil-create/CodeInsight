#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for(ll b = K + 1; b <= N; ++b) {
        //if(b == 1) continue;
        ans += N/b*(b-K);
        if(K == 0) --ans;
        if( N/b*b + K <= N) 
            ans += min(N, (N/b + 1)*b - 1) - N/b*b - K + 1;
    }
    cout << ans << endl;
    return 0;
}