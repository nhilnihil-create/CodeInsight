#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
ll sum(ll x){
	ll ret=0;
	while(x){
		ret+=x%10;
		x/=10;
	}
	return ret;
}
vector<ll>v;
int main(){
	int n;
	scanf("%d",&n);
	ll dec=1;
	for(int i=0;i<15;i++){
		for(int j=2;j<=9*(i+1)+1;j++){
			v.pb(dec*j-1);
		}
		dec*=10;
	}
	sort(v.begin(),v.end());
	int k=unique(v.begin(),v.end())-v.begin();
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			if(v[i]*sum(v[j])>v[j]*sum(v[i])){
				v.erase(v.begin()+i--);
				break;
			}
		}
	}
	for(int i=0;i<n;i++)printf("%lld\n",v[i]);
}