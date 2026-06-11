#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

#define REP(i,n) for(int i=0; i<n; i++)
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
 
#define mod 1000000007 //1e9+7(prime number)
#define INF 10000000000000000000 //1e18
#define SIZE 200005

using namespace std;
typedef long long ll;

int n;
ll lx, x[SIZE], ans=INF;

ll calc(int k){
	// cerr << "calc(" << k << ")\n";
	ll tmpans =  k*lx;
	int j = 1;
	for (int i=0; k*i+j<=n; i++){
		// debug(i);
		for (j=1; j<=k && k*i+j<=n; j++){
			if (i==0){
				tmpans += 5*x[n-j];
			}else{
				tmpans += (2*(i+1)+1)*x[n-(k*i+j)];
			}
			// debug(j);
			// debug(tmpans);
		}
		// debug(tmpans + lx*n);
		j = 1;
	}
	return tmpans + lx*n;
}

int main(){	
	cin >> n >> lx;
	
	REP(i,n) cin >> x[i];
	
	if (n==1){
		cout << calc(1) << endl;
		return 0;
	}else if (n==2){
		cout << min(calc(1), calc(2)) << endl;
		return 0;
	}
	
	// n >= 3
	
	int l=2, r=n;	// [l, r)
	ans = calc(1);
	
	while (r-l>1){
		// debug(r);
		// debug(l);
		int k = (r+l)/2;
		// debug(k);
		if (calc(k) - calc(k-1)<=0){
			l = k;
		}else{
			r = k;
		}
	}
	
	// cerr << "-------------\n";
	
	// debug(r);
	// debug(l);
	
	ans = min(ans, calc(l));
	
	cout << ans << endl;
	return 0;
}
