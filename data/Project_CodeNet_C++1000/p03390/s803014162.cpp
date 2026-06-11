#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

using namespace std;

typedef long long ll;

int Q;

ll A,B;

int main(){
	cin>>Q;
	REP(q,Q){
		cin>>A>>B;
		if (A<B) swap(A,B);
		ll lb=B,ub=A+1;
		while(ub-lb>1){
			ll mid=(lb+ub)/2;
			if (mid*mid<A*B){
				lb=mid;
			}else{
				ub=mid;
			}
		}
		ll ans=2*(lb-1);
		if (lb*(lb+1)<A*B){
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}