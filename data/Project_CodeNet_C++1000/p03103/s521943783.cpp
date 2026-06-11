#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct{ll a,b;} P;
ll f(P p,P q){return p.a>q.a;}
ll n,m,i,s=0;
P x[100007];
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(cin>>n>>m;i<n;) cin>>x[i].a>>x[i++].b;
	sort(x,x+n,f);
	for(;m*i--;) s+=min(x[i].b,m)*x[i].a, m-=min(m,x[i].b);
	cout<<s;
}
