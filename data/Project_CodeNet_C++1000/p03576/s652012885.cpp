#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll l[52],r[52];
int main() {
	ll n,k,ans=INF;
	cin>>n>>k;
	for(ll i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		l[i]=x;r[i]=y;
	}
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			for(ll m=0;m<n;m++){
				for(ll o=0;o<n;o++){
					ll sum=0;
					ll ux=l[i],dx=l[j],uy=r[m],dy=r[o];
					if(ux<dx){
						swap(ux,dx);
					}
					if(uy<dy){
						swap(uy,dy);
					}
					for(ll p=0;p<n;p++){
						ll nowx=l[p],nowy=r[p];
						if(nowx>=dx&&nowx<=ux&&nowy<=uy&&nowy>=dy){
							sum++;
						}
					}
					if(sum>=k){
						ll sq=(ux-dx)*(uy-dy);
						ans=min(ans,sq);
					}
				}
			}
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}