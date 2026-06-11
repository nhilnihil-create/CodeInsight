#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
void File(){
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
}
#define REP(i,a,b) for(register int i=a;i<=b;++i)
#define DREP(i,a,b) for(register int i=a;i>=n;--i)
#define ll long long
const int maxn=1e6+10;
ll n,a,b;
int s[maxn];
int main(){
	//File();
	cin>>n>>a>>b;
	if(n>a*b || n<a+b-1)
		cout<<-1<<endl;
	else{
		REP(i,1,a)s[i]=n-a+i;
		if(b!=1){
			ll unit=(n-a)/(b-1),res=(n-a)%(b-1);
			int p=a,from=n-a-unit+1,last=n-a;
			while(p!=n){
				if(res)--res,--from;
				REP(i,from,last)
					s[++p]=i;
				last=from-1;
				from=from-unit;
			}
		}
		REP(i,1,n)cout<<s[i]<<" ";
	}
	return 0;
}
