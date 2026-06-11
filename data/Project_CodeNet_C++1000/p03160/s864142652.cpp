/*input
4
10 30 40 20
*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long 
#define vl vector<ll> 
#define pl pair<ll,ll> 
#define vpl vector<pl> 
#define vvl vector<vl> 
using namespace std;
const int N = 1e5+5;
ll h[N], ans[N];
int main()

{
	ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
   
    ll n;
    cin>>n;
    for(int i=0; i<n; ++i) cin>>h[i];
    ans[n-1]=0;
	ans[n-2] = (ll)(abs(h[n-1]-h[n-2]));
	// ans[i] --> i se n tak jaane ki cost
	for(int i=n-3; i>=0; --i){
		// ans[3] = min(ans[4]+3 to 4,    ans[5] + 3 to 5)
		ans[i] = min(ans[i+1]+(ll)(abs(h[i]-h[i+1])), ans[i+2]+(ll)(abs(h[i]-h[i+2])));
	}


	cout<<ans[0];
        

  return 0;
   		
}