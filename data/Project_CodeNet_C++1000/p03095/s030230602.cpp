#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
const long long MOD = 1e9 + 7;
int main()
{
    int N;
    string S;
    cin >> N >> S;

    ll ans = 1;
    map<char, ll> mp;

    rep(i, N) mp[S[i]]++;

    rep(i, 26) {
        ans *= mp[i + 'a'] + 1;
        ans %= MOD;
    }

    cout << ans - 1 << endl;
    return 0;
}