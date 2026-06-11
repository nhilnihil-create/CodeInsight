#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    string s; cin >> s;

    int a = (s[0] - '0') * 10 + (s[1] - '0');
    int b = (s[2] - '0') * 10 + (s[3] - '0');

    int f = 0;
    if (a > 12 || a == 0)
        f += 2;
    if (b > 12 || b == 0)
        f++;

    if (f == 0) cout << "AMBIGUOUS" << endl;
    else if (f == 1) cout << "MMYY" << endl;
    else if (f == 2) cout << "YYMM" << endl;
    else if (f == 3) cout << "NA" << endl;
}