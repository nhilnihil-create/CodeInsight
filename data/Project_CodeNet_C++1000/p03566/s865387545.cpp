#include<bits/stdc++.h>
using namespace std;
const int maxn=105;

int n;
double v[maxn],t[maxn];
double cur,ans;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",&t[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&v[i]);
	}
	for(int i=0;i<n;i++){
		double inc,kep,dec;
		double lim=100000000.0;
		double tmp=0.0;
		for(int j=i+1;j<=n;j++){
			lim=min(lim,v[j]+tmp);
			tmp+=t[j];
		}
		inc=min(v[i]-cur,(lim+t[i]-cur)*0.5);
        inc=min(inc,t[i]);
        dec=max(0.0,cur+inc-lim);
        kep=t[i]-inc-dec;
        ans+=0.5*(cur*2.0+inc)*inc;
        ans+=(cur+inc)*kep;
        ans+=0.5*((cur+inc)*2.0-dec)*dec;
        cur+=inc;
        cur-=dec;
	}
	printf("%f",ans);
	return 0;
}