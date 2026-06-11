//arc096_d.cpp
//Mon Jan 27 18:19:19 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll n,c;
	cin >> n >> c;

	ll x[n],v[n];
	ll rightscore[n+1];
	rightscore[0] = 0;
	ll totalrightscore[n+1];
	totalrightscore[0] = 0;
	ll maxrightscore[n+1];
	maxrightscore[0] = 0;
	for (int i=0;i<n;i++){
		cin >> x[i] >> v[i];
		totalrightscore[i+1] = totalrightscore[i]+v[i];
		rightscore[i+1] = totalrightscore[i+1]-x[i];
		maxrightscore[i+1] = max(maxrightscore[i],rightscore[i+1]);
	}

	ll leftscore[n+1];
	leftscore[n] = 0;
	ll totalleftscore[n+1];
	totalleftscore[n] = 0;
	ll maxleftscore[n+1];
	maxleftscore[n] = 0;
	for (int i=n-1;i>=0;i--){
		totalleftscore[i] = totalleftscore[i+1]+v[i];
		leftscore[i] = totalleftscore[i]-(c-x[i]);
		maxleftscore[i] = max(maxleftscore[i+1],leftscore[i]);
	}

	ll ans = 0;
	ll revtotal[n+1];
	revtotal[n] = 0;
	for (int i=n-1;i>=0;i--){
		revtotal[i] = revtotal[i+1]+v[i];
		ll temp = max(revtotal[i]-(c-x[i]),
					  maxrightscore[i]+revtotal[i]-(c-x[i])*2);
		ans = max(ans,temp);
	}

	ll fortotal[n+1];
	fortotal[0] = 0;
	for (int i=0;i<n;i++){
		fortotal[i+1] = fortotal[i]+v[i];
		ll temp = max(fortotal[i+1]-x[i],
					  fortotal[i+1]-x[i]*2+maxleftscore[i+1]);
		ans = max(ans,temp);
	}

//	revtotal[0] = revtotal[1]+v[0];
//	ll temp = revtotal[0]-(c-x[0]);
//	ans = max(ans,temp);

	cout << ans << endl;
//	printf("%.4f\n",ans);
}