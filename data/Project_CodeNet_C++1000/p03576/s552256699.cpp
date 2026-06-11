#include <bits/stdc++.h>

using namespace std;

const int N=1e6+3;

const double eps=0.000000001;

#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef long long ll;

const int dx[]={1,-1,0,0},
		  dy[]={0,0,1,-1};

const int inf=1e9;

int n,m,a[N],b[N],k,q,u,v,x,y,tc,c,l,r,ans;

char s[N];

void IO(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("test.txt","r",stdin);
	#endif
}


int main(){
	//IO();
	ll ans=4e18;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d %d",&a[i],&b[i]);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=j;k<n;k++){
				for(int l=k;l<n;l++){
					int min_x=min(min(a[i],a[j]),min(a[k],a[l]));
					int max_x=max(max(a[i],a[j]),max(a[k],a[l]));
					int min_y=min(min(b[i],b[j]),min(b[k],b[l]));
					int max_y=max(max(b[i],b[j]),max(b[k],b[l]));
					int cnt=0;
					for(int ii=0;ii<n;ii++)
						if (! (a[ii]>max_x || a[ii]<min_x || b[ii]>max_y || b[ii]<min_y) )
							cnt++;
					if (cnt>=m)
						ans=min(ans,(ll)(max_x-min_x)*(max_y-min_y));
				}
			}
		}
	}
	printf("%lld\n",ans);
}
