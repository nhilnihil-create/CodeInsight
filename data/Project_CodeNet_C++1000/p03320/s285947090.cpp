#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Lim = 1e4 + 10;
int n;
vector <ll> V;
ll S(ll x) {
	ll res=0;
	while(x) {
		res+=x%10;
		x/=10;
	}
	return res;
}
ll merge(ll x,int k) 
{
	while(k--) 
		x=x*10+9;
	return x;
}
double calc (ll x) {
	return (double) x/S(x);
}
void Work() {
	for(int i=1;i<=9;++i) 
		V.push_back(i);
	ll x=1;int k=1;
	while(merge(x,k) <=1e15) 
	{
		ll now=merge(x,k) ;
		ll nxt=merge(x+1,k) ;
		if(calc(now) <= calc(nxt)) 
		{
			x++;
			V.push_back(now) ;
		}
		else {
			x/=10;
			k++;
		}
	}
	for(int i=0;i<n;++i) 
		cout<<V[i]<<endl;
}
int main() {
//	freopen("D.in","r",stdin);
//	freopen("D.out","w",stdout);
	scanf("%d",&n);
	Work() ;
	return 0;
}
