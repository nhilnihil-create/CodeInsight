#include<bits/stdc++.h> 
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define per(i,l,r) for (int i=l;i>=r;i--)
using namespace std;
typedef unsigned long long ull;
const ull mm=419;
const ull mm2=31;
const ull mm3=998244353;
int n;
char s[60];
ull ans;
map<ull,int> mp;
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	int all=1<<n;
	rep(i,0,all-1){
		ull h1=0,h2=0;
		rep(j,0,n-1) {
			if (i&(1<<j)) h1=h1*mm+s[j]-'a'+1;
		}
		per(j,n-1,0) {
			if (~i&(1<<j)) h2=h2*mm2+s[j]-'a'+1;
		}
		h1=h1*mm3+h2;
		mp[h1]++;
	}
	rep(i,0,all-1){
		ull h1=0,h2=0;
		rep(j,0,n-1) {
			if (i&(1<<j)) h1=h1*mm2+s[n+j]-'a'+1;
		}
		per(j,n-1,0) {
			if (~i&(1<<j)) h2=h2*mm+s[n+j]-'a'+1;
		}
		h2=h2*mm3+h1;
		ans+=mp[h2];
	}
	printf("%lld\n",ans);
	return 0;
}