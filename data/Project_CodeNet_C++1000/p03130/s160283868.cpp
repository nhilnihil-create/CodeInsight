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
int main()
{
    vector<int> v(4);
    rep(i, 3) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a]++; v[b]++;
    }

    sort(v.rbegin(), v.rend());

    if (v[0] == 2 && v[1] == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}