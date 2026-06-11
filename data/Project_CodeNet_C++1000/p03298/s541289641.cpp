#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
string a,b;
map<pair<string,string>,int>m;
char s[40];
int main(){
	int n,i,j;
	ll ans;
	scanf("%d%s",&n,s);
	reverse(s+n,s+n*2);
	for(i=0;i<1<<n;i++){
		a=b="";
		for(j=0;j<n;j++)(i>>j&1?a:b).append(1,s[j]);
		m[make_pair(a,b)]++;
	}
	ans=0;
	for(i=0;i<1<<n;i++){
		a=b="";
		for(j=0;j<n;j++)(i>>j&1?a:b).append(1,s[j+n]);
		ans+=m[make_pair(a,b)];
	}
	printf("%lld",ans);
}