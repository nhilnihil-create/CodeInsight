#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN=3e5+7;

ll from[MAXN],to[MAXN];

map<ll,ll> Map;

ll n;
ll a[MAXN],b[MAXN],siz[MAXN],sum[MAXN];

bool cmp(const ll &A,const ll &B){return a[A]>a[B];}
bool cmp2(const ll &A,const ll &B){return A>B;}

ll minn1=1e18,minn2;

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=i;
		Map[a[i]]=i;
		siz[i]=1;
		if(minn1>a[i]) {
			minn1=a[i];
			minn2=i;
		}
	}
	sort(b+1,b+1+n,cmp);
	sort(a+1,a+1+n,cmp2);
	for(ll i=1,i2;i<n;i++) {
		i2=Map[a[i]-abs(n-2*siz[b[i]])];
		if(i2!=0&&a[i]-abs(n-2*siz[b[i]])!=a[i]) {
			siz[i2]+=siz[b[i]];
			sum[i2]+=sum[b[i]]+siz[b[i]];
			from[i]=i2;
			to[i]=b[i];
		}
		else {
			cout<<-1<<endl;
			return 0;
		}
	}
	if(minn1!=sum[minn2]) {
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<n;i++) {
		cout<<from[i]<<" "<<to[i]<<endl;
	}
}
