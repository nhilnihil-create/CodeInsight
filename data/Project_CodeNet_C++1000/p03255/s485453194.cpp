#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef unsigned long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

ll energy(ll i,ll x){
	if(i == 1) return 5*x;
	else return (2*i+1)*x;
}


int main()
{
	ll N,X;
	cin >> N >> X;
	vector<ll> x(N);
	for(ll i = 0; i < N; i++){
		cin >> x[i];
	}

	vector<ll> sum(N);
	for(ll i = 0; i < N; i++){
		sum[i] = x[i] + (i!=0 ? sum[i-1]:0);
	}


	ll ans = 1e18;
	for(ll i = 1; i <= N; i++){
		ll res = (i+N)*X;
		//cout << "i = " << i << endl;
		for(ll j = 1; j <= (N+i-1)/i; j++){
			if(N<(j-1)*i+1) break;
			res += energy(j,sum[N-(j-1)*i-1]-(N>=j*i+1 ? sum[N-j*i-1]:0));

			//cout << N-(j-1)*i-1 << "   " << ((N-j*i-1>=0) ? N-j*i-1:0) <<   endl;
		}
		ans = min(res,ans);
	}

	cout << ans << endl;

	return 0;
}