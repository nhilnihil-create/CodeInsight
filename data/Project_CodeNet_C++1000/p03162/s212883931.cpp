#include <bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lp(i, n) for(int i = 0; i < n; i++)
#define rlp(i, n) for(int i = n-1; i >= 0; i--)
#define loop(i, a, b) for(int i = a; i <= b; i++)
#define rloop(i, a, b) for(int i = a; i >= b; i--)
#define mem(a, val) memset(a, val, sizeof a);
#define test int t; cin>> t; while(t--)
#define all(v) v.begin(),v.end()
#define ll long long
#define ld long double
#define mp_ make_pair
#define pb push_back
#define sz(s) (int)s.size()
const int MAX = 1e5 + 5;
const int inf = 1e9+1;
const ll OO = 1e18;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
int n, a[MAX][3], dp[MAX][3];
int solve(int i = 0, int lst = -1){
    if(i == n) return 0;

    if(lst != -1 && dp[i][lst] != -1)
        return dp[i][lst];

    int mx = 0;
    lp(j, 3){
        if(j == lst) continue;
        mx = max(mx, solve(i + 1, j) + a[i][j]);
    }
    return dp[i][lst] = mx;
}
int main()
{
    cin>> n;
    lp(i, n){
        lp(j, 3) cin>> a[i][j];
    }
    mem(dp, -1);
    cout<< solve() <<"\n";

    return 0;
}
