#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define de(x) cout<<#x<<"="<<x<<endl
	#define rff freopen("input.txt","r",stdin)
	#define wtf freopen("input.txt","w",stdout)
	#include "Debug.h"
#else
	#define de(x)
	#define rff
#endif

#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,n) for (int i=1;i<=(int)(n);i++)
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define vi vector <int>
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define re return
#define se second
#define fi first
const int INF=0x7fffffff;
const int MAXN=1e5+3;
const int BASE=100000;
#define low_bit(x) x&(-x)

int bit[MAXN*2],n,a[MAXN];
vi v;

ll query(int x){
	x+=BASE;
	ll r=0;
	while (x){
		r+=bit[x];
		x-=low_bit(x);
	}
	re r;
}

void add(int x){
	x+=BASE;
	while (x<MAXN*2){
		bit[x]++;
		x+=low_bit(x);
	}
}

int main(){
	fio;
	cin>>n;
	For(i,n){
		cin>>a[i];
		v.pb(a[i]);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	ll l=0,r=v.size(),mid,x,cnt;
	ll tar=(ll)(n)*(n+1)/2/2;
	while (l<r-1){
		memset(bit,0,sizeof(bit));
		cnt=0;	
		mid=(l+r)>>1;
		x=0;
		add(0);
		For(i,n){
			if (a[i]>=v[mid]) x++;
			if (a[i]<v[mid]) x--;
			cnt+=query(x);
			add(x);
		}
		if (cnt<tar){
			r=mid;
		}else{
			l=mid;
		}
	}
	cout<<v[l]<<endl;
	re 0;
}