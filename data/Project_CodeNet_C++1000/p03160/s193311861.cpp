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
int n, a[MAX], dp[MAX];
int solve(int i = 0){
    if(i == n - 1) return 0;

    if(dp[i] < 1e9) return dp[i];

    int choice1 = inf, choice2 = inf;

    if(i + 1 < n)
        choice1 = solve(i + 1) + abs(a[i + 1] - a[i]); // 20 10 20 // 20 10 0

    if(i + 2 < n)
        choice2 = solve(i + 2) + abs(a[i + 2] - a[i]); // 30 20

    return dp[i] = min(choice1, choice2);
}
int main()
{
    cin>> n;
    lp(i, n)
        cin>> a[i];

    mem(dp, 63);
    cout<< solve() <<"\n";

    return 0;
}
