#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define O 100005

int d0[200050],d1[200050];
int n;

int main(){
	scanf("%d",&n);
	fore(_,0,n){
		int l,r;
		scanf("%d%d",&l,&r);
		d0[l+O]++;
		d1[r+O]++;
	}
	d0[O]++;d1[O]++;
	ll r=0;
	int q0=0,q1=n+1;
	fore(i,0,200050)q0+=d1[i],q1-=d0[i],r+=min(q0,q1);
	printf("%lld\n",r*2);
	return 0;
}