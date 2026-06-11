/*input
5 3
10 30 40 50 20
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
const ll N = 1e5 +5;
vl t;
ll frog(vl& v,ll n,ll k)
{
   	
   	ll cst;

	t [0] =  0;
	for(ll i = 1;i <= n;i++)
	{	
		ll mn = LONG_MAX;
		for(ll j = 1;j <= k;j++){
			if(i >= j)cst = abs(v[i-j]-v[i])+t[i-j];
			mn = min(mn,cst);
		}
		 t[i] = mn;

	}
	return t[n];

	// if(t[n] != -1)return t[n];
	// if(n == 0)return 0;
	// cst1 = (abs(v[n-1]-v[n])+frog(v,n-1));
	// if(n >= 2){
	// cst2 = (abs(v[n-2]-v[n])+frog(v,n-2));}
	// else cst2 = INT_MAX;
	// return t[n]  = min(cst1,cst2);

	
 
}

int main()

{
	ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
   
   ll n,h,k ;
   vl v;

   cin >> n >> k;
   t.resize(n);
   for(auto x = 0 ;x< n;x++)cin >> h,v.pb(h),t[x] = -1;
  	ll cst =  frog(v,n-1,k);
   cout << cst;


        

  return 0;
   		
}
