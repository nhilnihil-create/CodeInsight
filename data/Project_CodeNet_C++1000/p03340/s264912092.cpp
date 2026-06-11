//bismillahir rahmanir rahim            //Author:Fayed Anik

#include <bits/stdc++.h> 

using namespace std;


#define         ll                         long  long
#define         lf                         double 
#define         pb(x)                      push_back(x)
#define         ull                        unsigned long long
#define         sfl(a)                     scanf("%lld",&a)
#define         sf(a)                      scanf("%d",&a)
#define         pf(a)                      printf("%d\n",a)
#define         pfl(a)                     printf("%lld\n",a)
#define         pdl(a)                     printf("%llf\n",a)
#define         FOR(x,n)                   for(ll x=1;x<=n;++x)
#define         vii                        vector< ll > v
#define         pi                         3.14159265359
#define         mex                        10000000
#define         pii                        pair< ll , ll >
#define         mem(m,a)                   memset( m, a,sizeof m)
#define         mp(a,b)                    make_pair(a,b)
#define         maxn                       100000
#define         mod                        1000000007
#define         INF                        1e17
#define         f1                         first
#define         f2                         second
#define         all(v)                     v.begin(),v.end()
#define         PI                         acos(-1)
#define         printminusone              printf("-1\n")
#define         bug                        printf("bug")

ll n,a,csum[200010],cxor[200010];

ll bs(ll x){
	ll lw=x,hi=n,ans=x;
	while(lw<=hi){
		ll mid=(lw+hi)>>1;
		if(csum[mid]-csum[x-1]==(cxor[mid]^cxor[x-1])){
			ans=mid;
			lw=mid+1;
		}
		else{
			hi=mid-1;
		}
	}

	return ans;
}
int main(){
	sfl(n);
	csum[0]=cxor[0]=0;
	FOR(i,n){
		sfl(a);
		csum[i]=csum[i-1]+a;
		cxor[i]=cxor[i-1]^a;
	}

	ll ans=0;

	for(ll i=1;i<=n;i++){
		ans += bs(i)-i+1;
	}

	pfl(ans);
}

