#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const int MOD = 1e9+7;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    cout << n - k + 1 << endl;


    return 0;
}