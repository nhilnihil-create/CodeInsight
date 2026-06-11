#include <bits/stdc++.h>
using namespace std;

# define ll long long 
# define VI vector<int>
# define VLL vector<ll>
# define PII pair<int,int> 
#define mp make_pair
#define pb push_back
# define PI acos(-1)
# define double long double
const int MxN = 10005 ; 
# define FOR(i,a,b) for(int i = a ; i < b ; ++i)
 
/* VARIABLES */

int n , h ;
vector<PII> s(MxN) ; 

/* END OF VARIABLES */



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL) ; 
	
	
	cin >> n >> h ; 
	int a ; 
	int mx = 0 ; 
	VI array(n) ; 
	FOR(i,0,n) {
		cin >>a >> array[i]; 
		mx = max(a,mx) ; 
	}
	VI tmp ; 
	FOR(i,0,n) {
		if(array[i] > mx)
			tmp.pb(array[i]) ; 
	}

	sort(tmp.begin(), tmp.end() , greater<int> ()) ;
	int cnt = 0 ; 
	for(int x : tmp) {
		h -= x ; 
		cnt++;
		if(h <= 0 ) {
			cout << cnt ;
			return 0 ; 
		}
	} 

	cout << cnt + (h + mx -1 )/mx ; 

	return 0 ; 
}

