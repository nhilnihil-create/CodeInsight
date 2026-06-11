#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    ll L[N], R[N];
    rep(i, N) cin >> L[i] >> R[i];
    sort(L, L+N, greater<ll>());
    sort(R, R+N);
    int i = 0;
    ll sum = 0;
    while(L[i] > R[i]){sum += L[i]-R[i]; i++;}
    ll ans = sum;
    if(i >= 1){
        ans = max(ans, sum-L[i-1]);
        ans = max(ans, sum+R[i-1]);
    }
    if(i*2 != N){
        ans = max(ans, sum+L[i]);
        ans = max(ans, sum-R[i]);
    }
    cout << ans*2 << endl;
}