#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define MP make_pair
#define F first
#define S second
#define sz(v) (ll)v.size()
#define inf 100000000000000
#define vll vector<ll>
#define pll pair<ll,ll>nnnn
using namespace std;
const int N=200004;

ll deg[5];
map<ll,ll>mp;
void solve()
{
	ll a,b,i;
	cin>>a>>b;
	deg[a]++;
	deg[b]++;
	cin>>a>>b;
	deg[a]++;
	deg[b]++;
	cin>>a>>b;
	deg[a]++;
	deg[b]++;
	for (i=1;i<=4;i++)
		mp[deg[i]]++;
	if(mp[1]==2 && mp[2]==2)
		cout<<"YES";
	else
		cout<<"NO";

}
int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
 
    
    return 0;
}