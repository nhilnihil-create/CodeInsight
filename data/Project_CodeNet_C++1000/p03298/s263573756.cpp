#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
using namespace std;
typedef unsigned long long ull;
map<pair<ull,ull>,int > mp;
int n;
char s[55];
ull ans;
int main(){
	scanf("%d%s",&n,s);
	rep(i,0,(1<<n)-1){
		ull a=0,b=0;
		rep(j,0,n-1) if (i&(1<<j)) a=a*233+s[j];
		for (int j=n-1;j>=0;j--) if ((i&(1<<j))==0) b=b*233+s[j];
		mp[make_pair(a,b)]++;
	}
	rep(i,0,(1<<n)-1){
		ull a=0,b=0;
		rep(j,0,n-1) if (i&(1<<j)) a=a*233+s[j+n];
		for (int j=n-1;j>=0;j--) if ((i&(1<<j))==0) b=b*233+s[j+n];
		ans+=mp[make_pair(b,a)];	
	}
	cout<<ans<<endl;
	return 0;
}