#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e5+5;
template<class T>inline void read(T &res)
{
char c;T flag=1;
while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}
int n;
char s[N];
int a[N],b[N];
int main(){
	read(n);
	cin>>s+1;
	for(int i=1;i<=n;i++)a[i]+=a[i-1]+(s[i]=='#');
	for(int i=n;i;i--)b[i]+=b[i+1]+(s[i]=='.');
	int ans=INF;
	for(int i=0;i<=n;i++){
		ans=min(ans,a[i]+b[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}
