#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VLL vector<ll>
# define PII pair<int,int> 
# define mp make_pair
# define pb push_back
# define PI acos(-1)
# define ld long double
const int MxN = 200001 ; 
# define FOR(i,a,b) for(int i = a ; i < b ; ++i)
# define RFOR(i,a,b) for(int i = a ; i >= b ; --i)
const int MOD = 1e9 + 7 ; 

/* VARIABLES */
int n  ;
VI a(MxN) ; 

/* END OF VARIABLES */



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ;  

	cin >> n ; 
	FOR(i,0,n) 
		cin >> a[i]; 
	map<ll,int> cnt ; 
	ll sum = 0,ans=0; 
	cnt[0]=1;
	FOR(i,0,n) {
		sum += a[i] ; 
		if(cnt[sum] > 0) 
			ans += cnt[sum] ; 
		cnt[sum]++;
	}
	cout << ans ; 
	

		
	return 0 ; 
}

