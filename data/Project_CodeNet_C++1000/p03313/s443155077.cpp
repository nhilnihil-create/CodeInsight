#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define endl '\n'

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

const int MX = 1e9 + 5;
const int N = 18;
const int SZ = (1 << 18) + 5;
int dp[N + 2][SZ][2];
int arr[SZ];
int n;

int solve(int idx, int msk, int have) {
    if (idx == -1) {
        if (have == 1)return arr[msk];
        return -MX;
    }

    int &ret = dp[idx][msk][have];
    if (~ret)return ret;

    if ((msk >> idx) & 1) {
        if (have == 1) {
            ret = max(solve(idx - 1, msk - (1 << idx), have), solve(idx - 1, msk, have));
        } else {
            ret = solve(idx - 1, msk, have);
            ret = max(ret, solve(idx - 1, msk - (1 << idx), have));
            ret = max(ret, solve(idx - 1, msk - (1 << idx), 1) + solve(idx - 1, msk, 1));
        }
    } else {
        ret = solve(idx - 1, msk, have);
    }

    return ret;
}

int main() {

#ifndef ONLINE_JUDGE
//    freopen("in.in", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    loop(i, (1 << n)) {
        cin >> arr[i];
    }

    int mx = 0;
    memset(dp, -1, sizeof dp);
    range(i, 1, (1 << n) - 1) {
        mx = max(mx, solve(n - 1, i, 2));
        cout << mx << endl;
    }


    return 0;
}
