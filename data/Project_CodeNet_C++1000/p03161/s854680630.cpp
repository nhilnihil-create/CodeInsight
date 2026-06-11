#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

// #define endl            "\n"
#define forn(i,x1,n)     for(int i=x1; i<n; i++)
#define forit(it, m)    for(decltype(m)::iterator it = m.begin(); it!=m.end(); ++it)
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x1)      __builtin_popcountll(x1)
#define zrobits(x1)      __builtin_ctzll(x1)
#define mod             1000000007
#define inf             1e18
#define ps(x1,y)         fixed<<setprecision(y)<<x1
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x1)            int x1; cin>>x1; while(x1--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


void zeus()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n;
int k;
vector<int> h;
int memo[100005];
int solve(int i) {
    if (i == n) {
        return 0;
    }
    forn(j, 1, k) {
        if (i == n - j) {
            return abs(h[n] - h[n - j]);
        }
    }
    if (memo[i] != -1) {
        return memo[i];
    }
    memo[i] = INT_MAX;
    forn(j, 1, k + 1) {
        memo[i] = min(memo[i], solve(i + j) + abs(h[i + j] - h[i]));
    }
    return memo[i];
}

int32_t main() {

    zeus();
    cin >> n;
    cin >> k;
    vector<int> x(n + 1);
    memset(memo, -1, sizeof memo);
    forn(i, 1, n + 1) {
        cin >> x[i];
    }
    h = x;

    cout << solve(1) << endl;






}






