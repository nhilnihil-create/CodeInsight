#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mp1(a,b,c) P1(a,P(b,c))

vector<P1> ret;
void solve(int n,int L){
	if(n==0)return;
	int x=L/2;
	solve(n-1,x);
	ret.push_back(mp1(n-1,n,0));
	if(x!=0){
		ret.push_back(mp1(n-1,n,x));
		if(L&1){
			ret.push_back(mp1(0,n,L-1));
		}
	}
}

int main(){
	int L;
	cin>>L;
	solve(19,L);
	printf("%d %d\n",20,(int)ret.size());
	for(int i=0;i<ret.size();i++){
		printf("%lld %lld %lld\n",ret[i].fr+1,ret[i].sc.fr+1,ret[i].sc.sc);
	}
}
