#include <bits/stdc++.h>
#define assem99 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define endll '\n'
#define sz(a) (int)(a).size()
#define RWFile freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
int dx[] = { 0, -1, 0, 1, -1, 1, -1, 1 };
int dy[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
const int MOD = 1e9 + 7, N = 2e6 + 5, oo = 1e9;
const double pi = acos(-1);
using namespace std;

int n;
ld arr[N], dp[3005][3005];
bool vis[3005][3005];
ld solve(int id, int cnt)
{
    if(id == n) return cnt == 0;
    if(vis[id][cnt]) return dp[id][cnt];
    ld ans = 0;
    ans += solve(id + 1, cnt - 1) * arr[id];
    ans += solve(id  + 1, cnt) * (1 - arr[id]);
    vis[id][cnt] = true;
    return dp[id][cnt] = ans;
}

int main()
{
    assem99
    cin>>n;
    ld ans = 0;
    for(int i = 0; i < n; i++) cin>>arr[i];
    for(int i = n / 2; i < n; i++) ans += solve(0, i + 1);
    cout<<fixed<<setprecision(10)<<ans;

    return 0;
}