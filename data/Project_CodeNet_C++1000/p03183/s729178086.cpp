#include<bits/stdc++.h>
using namespace std;   //author: madmin2619/mintu_agarwal
     
#define nfs() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define endl "\n"
#define pb push_back
#define pf push_front
#define forin(i, n) for(int i=0;i<n;i++)
#define tr(c, it) for(auto it=c.begin();it!=c.end();it++)
#define sz(c) c.size()
#define all(c) c.begin(),c.end()
#define ff first
#define ss second
#define m_p(x, y) make_pair(x, y)
     
const int M = 1e9 + 7;
const int N = 2e4+100;

bool comp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
	return (a.ff+ a.ss.ff) < (b.ff + b.ss.ff);
}

int32_t main(){
    nfs()
    int t, n, i, j, k;
    cin >> n;
    vector<pair<int, pair<int, int> > > v(n);
    forin(i, n)
    	cin >> v[i].ss.ff >> v[i].ff >> v[i].ss.ss;
    int dp[N];
    for(int i=0;i<N;i++)
    	dp[i]=0;
    sort(all(v), comp);
    for(int i=0;i<n;i++){
    	for(int j=v[i].ff;j>=0;j--){
    		dp[j+v[i].ss.ff]=max(dp[j+v[i].ss.ff], dp[j]+v[i].ss.ss);
    	}
    }
    int ans = 0;
    for(int i=0;i<N;i++)
    	ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}