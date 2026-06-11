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
    vector<int> N(4);
    cin >> N[0] >> N[1] >> N[2] >> N[3];
    sort(all(N));
    if (N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}