#include <cstdio>
#include <bitset>
#include <cstring>
#define rep(a,b,c) for(int a=b;a<=c;a++)
using std::bitset;
bitset<4000001> s;
int n,a[2001],S,sum,ans;
int main() {
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]),sum+=a[i]; S=sum; sum/=2;
	s[0]=1;
	rep(i,1,n) s|=(s<<a[i]);
	rep(i,0,sum) if(s.test(i)) ans=i;
	printf("%d",S-ans);
}