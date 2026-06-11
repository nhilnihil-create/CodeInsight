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
    vector<int> ABC(3);
    rep(i, 3) cin >> ABC[i];

    sort(all(ABC));

    int A1 = ABC[2] - ABC[0], A2 = ABC[2] - ABC[1];
    int ans = A1 / 2;
    ans += A2 / 2;

    if (A1 % 2 && A2 % 2) {
        ans++;
    }
    else if (A1 % 2 || A2 % 2) {
        ans += 2;
    }

    cout << ans << endl;
    return 0;
}