#include<bits/stdc++.h>
using namespace std;
int n;
long long a[10010],b[10010],sa,sb,so,o[10010],oo; 
void sad(){cout<<"No"<<endl;exit(0);}
int main(){
	#ifdef FILIN
		#ifndef DavidDesktop
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) sa+=a[i];
	for(int i=1;i<=n;i++) sb+=b[i];
	for(int i=1;i<=n;i++){
		o[i]=max(a[i],b[i]);
		if((a[i]%2LL)==1LL) o[i]+=(1LL-(o[i]%2LL));
		else o[i]+=(o[i]%2LL);
	}
	for(int i=1;i<=n;i++) so+=o[i];
	if(sa>sb) sad();
	oo=sb+sb-sa;
	if(so>oo) sad();
	if((so%2LL)!=(oo%2LL)) sad();
	cout<<"Yes"<<endl;
	return 0;
}

