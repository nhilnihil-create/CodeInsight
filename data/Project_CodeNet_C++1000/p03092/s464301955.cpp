#include<bits/stdc++.h>
using namespace std;
const long long Inf=1e18;

int gi() {
	int x=0,o=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*o;
}

int main() {
	int n=gi(),a=gi(),b=gi();
	vector<int> p(n+1);
	for(int i=1;i<=n;i++) p[i]=gi();
	vector<int> q(n+1);
	for(int i=1;i<=n;i++) q[p[i]]=i;
	vector<long long> f(1,0);
	for(int i=1;i<=n;i++) {
		vector<long long> new_f(i+1,Inf);
		for(int j=0;j<i;j++) {
			if(q[i]>q[j]) {
				new_f[i]=min(new_f[i],f[j]);
				new_f[j]=min(new_f[j],f[j]+b);
			}
			else {
				new_f[j]=min(new_f[j],f[j]+a);
			}
		}
		swap(f,new_f);
	}
	printf("%lld\n",*min_element(f.begin(),f.end()));
	return 0;
}
