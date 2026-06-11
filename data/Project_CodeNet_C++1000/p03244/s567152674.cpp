#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
using Graph = vector<vector<int>>;
using Graphl = vector<vector<ll>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define FOR(itr, v) for (auto itr = (v).begin(); itr != (v).end(); ++itr)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
#define rALL(a)  (a).rbegin(),(a).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> void PrintVector(const vector<T> &vec) {for (auto val : vec) cout << val << " "; cout << endl;}
const long long INF = 1LL << 60;
const long long minusINF = -(1LL << 40);
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int n; cin >> n;
    map<int, int> ev, od;
    rep(i, n)
    {
        int v; cin >> v;
        if (i % 2 == 0) od[v]++;
        else ev[v]++;
    }

    int ev1 = 0, od1 = 0;
    int ec1 = 0, ec2 = 0, oc1 = 0, oc2 = 0;
    int cnt = 0;

    FOR(itr, ev)
    {
        if (itr->second > cnt)
        {
            cnt = itr->second;
            ev1 = itr->first;
        }
    }
    ec1 = cnt;
    cnt = 0;

    FOR(itr, ev)
    {
        if (itr->second > cnt && itr->first != ev1)
        {
            cnt = itr->second;
        }
    }
    ec2 = cnt;
    cnt = 0;

    FOR(itr, od)
    {
        if (itr->second > cnt)
        {
            cnt = itr->second;
            od1 = itr->first;
        }
    }
    oc1 = cnt;
    cnt = 0;

    FOR(itr, od)
    {
        if (itr->second > cnt && itr->first != od1)
        {
            cnt = itr->second;
        }
    }
    oc2 = cnt;

    if (ev1 == od1)
    {
        cout << min(n - ec1 - oc2, n - ec2 - oc1) << endl;
    }
    else
    {
        cout << n - ec1 - oc1 << endl;
    }
}