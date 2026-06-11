#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=2e5;
int N,a[MAX_N],b[MAX_N],temp[MAX_N];
ll ans[29];
int main(){
	cin>>N;
	REP(i,N){
		cin>>a[i];
	}
	REP(i,N){
		cin>>b[i];
	}
	REP(k,29){
		REP(i,N){
			temp[i]=b[i]%(1<<(k+1));
		}
		sort(temp,temp+N);
		REP(i,N){
			int a2=a[i]%(1<<(k+1));
			ans[k]+=lower_bound(temp,temp+N,(1<<(k+1))-a2)-lower_bound(temp,temp+N,(1<<k)-a2);
			ans[k]+=lower_bound(temp,temp+N,(1<<(k+2))-a2)-lower_bound(temp,temp+N,(1<<k)*3-a2);
		}
	}
	ll ans2=0;
	REP(i,29){
		ans2+=ans[i]%2*(1<<i);
	}
	cout<<ans2<<endl;
	return 0;
}