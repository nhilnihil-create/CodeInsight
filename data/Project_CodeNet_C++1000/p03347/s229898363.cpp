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
    ll A[N];
    rep(i, N) cin >> A[i];
    if(A[0]) {cout << -1 << endl; exit(0);}
    ll ans = 0;
    rep(i, N-1){
        if(A[i]+1 == A[i+1]) continue;
        elif(A[i] >= A[i+1]) ans += A[i];
        else {cout << -1 << endl; exit(0);}
    }
    ans += A[N-1];
    cout << ans << endl;
}