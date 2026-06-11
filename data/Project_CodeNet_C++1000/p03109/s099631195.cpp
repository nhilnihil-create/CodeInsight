#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a)  (a).rbegin(),(a).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void PrintVector(const vector<int> &vec)
{
    for (auto val : vec)
        cout << val << " ";
    cout << endl;
}

int main()
{
    string s; cin >> s;
    vector<int> day(3, 0);
    int j = 0;
    rep(i, s.size())
    {
        if (s[i] != '/')
        {
            day[j] = day[j] * 10 + s[i] - '0';
        }
        else j++;
    }

    if (day[0] <= 2019 && day[1] <= 4 && day[2] <= 30)
        cout << "Heisei" << endl;
    else
        cout << "TBD" << endl;
}