#include<bits/stdc++.h>
// #include <boost/multiprecision/mpfr.hpp>  // Defines the Backend type that wraps MPFR
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(long long int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
 
using namespace std;
 
 
int main(){
	long long int n;
	cin >> n;
	long long int a[n],b[n];
	forn(i,0,n) cin >> a[i];
	forn(i,0,n) cin >> b[i];
	long long int ans = 0;
	long long int mxk = 30;
	while(mxk--){
		// checking for mxk bit;
		long long int ca[n],cb[n];
		memcpy(ca,a,sizeof(ca));
		memcpy(cb,b,sizeof(cb));
		long long int t = (1<<mxk);
		forn(i,0,n){
			ca[i] = (a[i]%(2*t));
			cb[i] = (b[i]%(2*t));
		}
		sort(cb,cb+n);
		long long int cnt = 0;
		forn(i,0,n){
			long long int l= 0 ,r = n-1;
			while(l<=r){
				long long int m  = l+r>>1;
				if(ca[i]+cb[m]>=t)
					r = m-1;
				else
					l = m+1;
			}
			// l gives the smallest j s.t. ai + b[j] >= t
			long long int jmin = l;
			l = 0;r = n-1;
			while(l<=r){
				long long int m = l+r>>1;
				if(ca[i]+cb[m]<2*t)
					l = m+1;
				else
					r = m-1;
			} 
			long long int jmax = r;
			if(jmax>=jmin)
				cnt += (jmax-jmin + 1);
			l = 0,r = n-1;
			while(l<=r){
				long long int m  = l+r>>1;
				if(ca[i]+cb[m]>=3*t)
					r = m-1;
				else
					l = m+1;
			}
			jmin = l;
			l = 0;r = n-1;
					jmax = n-1;
			if(jmax>=jmin)
			cnt += (jmax-jmin + 1);
		}
		if(cnt%2==1)
			ans += (1<<mxk);
	}
	cout << ans << endl;
 
}