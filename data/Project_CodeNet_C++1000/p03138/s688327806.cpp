#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+3;
int N;
ll K;
ll A[MAX_N];

ll cal(int x)
{
	ll res = 0;
	for(int p=0;p<x;++p){
		int z=0,o=0;
		for(int i=0;i<N;++i){
			if(A[i]>>p&1) o++;
			else z++;
		}
		res += (1LL<<p)*max(z,o);
	}
	
	for(int i=0;i<N;++i){
		res += A[i] & (1LL<<x);
	}

	for(int p=x+1;p<63;++p){
		for(int i=0;i<N;++i){
			res += (K&(1LL<<p))^(A[i]&(1LL<<p)); 
		}
	}
	return res;
}

void solve()
{
    if(K == 0) cout << accumulate(A,A+N,0LL) << '\n';
    else{
	    ll ans = 0;
	    for(int i=0;i<N;++i) ans+=A[i]^K;
	    for(int p=63;p>=0;--p)if(K>>p&1){
	        ll cur = cal(p);
            ans = max(ans, cur);
	    }
	    cout << ans << '\n';
    }
}

int main()
{
	cin >> N >> K;
	for(int i=0;i<N;++i) cin >> A[i];
	solve();
	return 0;
}