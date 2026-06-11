#include "bits/stdc++.h"
using namespace std;
#define repr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repr(i,0,n)
#define reprrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) reprrev(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define mp make_pair
#define mt make_tuple
#define MOD 1000000007
#define PI 3.1415926535
#define SEGMAX 131072
typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<Pi> vPi;
typedef vector<Pll> vPll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<ll>> vvll;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<double>> vvd;
typedef vector<vector<Pi>> vvPi;
typedef priority_queue<int, vector<int>, greater<int>> pqli;
typedef priority_queue<ll, vector<ll>, greater<ll>> pqlll;
typedef priority_queue<Pi, vector<Pi>, greater<Pi>> pqlP;
string YN(bool y) { return (y?"YES":"NO"); }
string yn(bool y) { return (y?"Yes":"No"); }
string ON(bool y) { return (y?"OK":"NG"); }
int main(void)
{
	ll n, c, ans=0;

	cin>>n>>c;

	vll x(n), v(n), vsum(n+1, 0), vinv(n+1, 0), vsummax(n+1), vinvmax(n+1);

	rep(i, n) cin>>x[i]>>v[i];

	rep(i, n) vsum[i+1]=vsum[i]+v[i];

	repr(i, 1, n+1) vsum[i]-=x[i-1];

	reprev(i, n) vinv[i]=vinv[i+1]+v[i];

	rep(i, n) vinv[i]-=(c-x[i]);

	
	rep(i, n+1){
		if(ans<vsum[i]) ans=vsum[i];
		if(ans<vinv[i]) ans=vinv[i];
	}

	if(n<=0){
		rep(i, n){
			rep(j, n){
				if(i<j){
					ll temp=vsum[i+1]+vinv[j]-x[i];
					if(ans<temp) ans=temp;

					temp=vsum[i+1]+vinv[j]-(c-x[j]);
					if(ans<temp) ans=temp;
				}
			}
		}
		cout<<ans<<endl;
	}else{
		ll max1=0;
		rep(i, n+1){
			if(max1<vsum[i]){
				max1=vsum[i];
			}
			vsummax[i]=max1;
		}
		rep(i, n){
			ll temp=vinv[i]+vsummax[i]-(c-x[i]);
			if(ans<temp) ans=temp;
		}


		max1=0;
		reprev(i, n+1){
			if(max1<vinv[i]){
				max1=vinv[i];
			}
			vinvmax[i]=max1;
		}
		repr(i, 1, n+1){
			ll temp=vsum[i]+vinvmax[i]-x[i-1];
			if(ans<temp) ans=temp;
		}

		cout<<ans<<endl;
	}
}