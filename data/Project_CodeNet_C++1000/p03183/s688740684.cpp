#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define REP(i,a,b) for (int i = a ; i <= b ; i++)
#define REPI(i,a,b) for (int i = a ; i >= b ; i--)
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const int OO = 1e9+7;
const int MOD = 1e9+7;
const int N = 1e3+7;
const int S = 2e4+7;

int s[N],w[N],v[N];
ll dp[S];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("teleport.in","r",stdin);
    //freopen("teleport.out","w",stdout);

    vector<pi> vec;
    int n;
    cin >> n;
    REP(i,1,n)
    {
        cin >> w[i] >> s[i] >> v[i];
        vec.PB({w[i]+s[i],i});
    }
    sort(vec.begin(),vec.end());
    ll ans = 0;

    REP(i,0,n-1)
    {
        int idx = vec[i].S;
        REPI(j,min(s[idx],S-w[idx]),0)
        {
            dp[j+w[idx]] = max(dp[j+w[idx]],dp[j]+v[idx]);
        }
    }

    REP(j,0,S-1) ans = max(ans,dp[j]);

    cout << ans << endl;

    return 0;
}
