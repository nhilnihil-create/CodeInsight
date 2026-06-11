#include<bits/stdc++.h>
using namespace std;
#define ar array
#define endl '\n'
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(m) Rep(i,1,m)
#define For(m) Rep(i,0,m-1)
#define Rbl(x,a) for(auto &x : a)
#define FIO ios::sync_with_stdio(0);   cin.tie(0);
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()
const ll INF = 0x3f3f3f3f3f3f3f3fll;
#define mod 1000000007

ll n;
vector<ll> pre;
vector<ll> dp;

void rec(int i, const vector<int>& not_taken, ll score_so_far, int mask, int group) {
    if(i == (int) not_taken.size()) {
        dp[mask] = max(dp[mask], score_so_far + pre[group]);
        return;
    }
    rec(i + 1, not_taken, score_so_far, mask, group);
    rec(i + 1, not_taken, score_so_far, mask ^ (1 << not_taken[i]),
        group ^ (1 << not_taken[i]));
}


int main() 
{
FIO

    cin >> n;
    vector<vector<ll>> in(n, vector<ll>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> in[i][j];
        }
    }
    pre.resize(1 << n);
    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) {
                for(int j = i + 1; j < n; ++j) {
                    if(mask & (1 << j)) {
                        pre[mask] += in[i][j];
                    }
                }
            }
        }
    }

    dp.resize(1 << n, -INF);
    dp[0] = 0;

    for(int mask = 0; mask < (1 << n); ++mask) {
        vector<int> not_taken;
        for(int i = 0; i < n; ++i) {
            if(!(mask & (1 << i))) {
                not_taken.push_back(i);
            }
        }
        rec(0, not_taken, dp[mask], mask, 0);
    }
    cout <<  dp[(1<<n)-1] << endl;
}
