#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read(){
	char ch=getchar();int x=0,f=1;
    while(ch<'0' || ch>'9') {
       if(ch=='-') f=-1;
	  	  ch=getchar();
	}
    while(ch<='9' && ch>='0') {
	   x=x*10+ch-'0';
	   ch=getchar();
	}
    return x*f;
}

ll s[1010101];
int a[1010101];

int main(){
	int n=read(),l=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		s[i]=s[i-1]+a[i];
	}
	ll ans=1e18; 
	for(int i=1;i<=n;i++){
		ll res=0;int pos=n;
		for(int j=1;j<=n/i+1;j++){
			res+=1ll*max(5,2*j+1)*(s[pos]-s[max(0,pos-i)]);
			if(res>ans) break;
			pos=max(0,pos-i);
		}
		res+=1ll*(i+n)*l;
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
