#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define ll long long
using namespace std;
const int N=1e6+6;
int main(){
	int n,q; static char s[N];
	scanf("%d%s%d",&n,s,&q);
	while (q--){
        int k,c1=0,c2=0; scanf("%d",&k);
        ll sm=0,ans=0;
        rep(i,1,n){
            if (i-k>=1){
                if (s[i-k-1]=='D') --c1,sm-=c2;
                if (s[i-k-1]=='M') --c2;
            }
            if (s[i-1]=='D') ++c1;
            if (s[i-1]=='M') ++c2,sm+=c1;
            if (s[i-1]=='C') ans+=sm;
        }
        printf("%lld\n",ans);
	}
}
