#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 200020;

ll n,ans,cntw;
string s;

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	ans=0,cntw=0;
	cin>>s;
	n = s.size();
	
	for(ll i = 0;i < n;i++){
		if(s[i]=='W'){
			++cntw;
			ans+=i;
		}
	}
	ans-=(cntw-1ll)*cntw/2; 
	printf("%lld\n",ans);
	
	return 0;
}
