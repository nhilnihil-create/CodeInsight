#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define gc getchar
#define pc putchar
#define cs const

inline
ll getint(){
	re ll num;
	re char c;
	re bool f=0;
	while(!isdigit(c=gc()))f^=c=='-';num=c^48;
	while(isdigit(c=gc()))num=(num<<1)+(num<<3)+(c^48);
	return f?-num:num;
}

inline
void outint(ll a){
	static char ch[23];
	if(a==0)pc('0');
	while(a)ch[++ch[0]]=a-a/10*10,a/=10;
	while(ch[0])pc(ch[ch[0]--]^48);
}

cs ll INF=0x3f3f3f3f3f3f3f3f;
cs int N=1005;
cs int dx[4]={1,-1,0,0};
cs int dy[4]={0,0,-1,1};
cs char s[4]={'R','L','D','U'};

int n;
ll x[N],y[N];
vector<ll> len;
bool flag;

signed main(){
	n=getint();
	for(int re i=1;i<=n;++i){
		x[i]=getint(),y[i]=getint();
		if(i^1){
			if(((x[i]^y[i])&1)!=flag)return puts("-1"),0;
		}
		else flag=(x[i]^y[i])&1;
	}
	for(int re i=0;i<=30;++i){
		len.push_back(1ll<<i);
	}
	if(flag==0)len.push_back(1);
	
	sort(len.rbegin(),len.rend());
	
	outint(len.size()),pc('\n');
	for(int re i=0;i<len.size();++i)
	outint(len[i]),pc(' ');
	pc('\n');
	
	for(int re i=1;i<=n;++i){
		ll xx=x[i],yy=y[i];
		for(int re j=0;j<len.size();++j){
			int pos;
			ll minn=INF;
			for(int re k=0;k<4;++k){
				ll tmpx=xx-len[j]*dx[k];
				ll tmpy=yy-len[j]*dy[k];
				if(abs(tmpx)+abs(tmpy)<minn){
					minn=abs(tmpx)+abs(tmpy);
					pos=k;
				}
			}
			pc(s[pos]);
			xx=xx-len[j]*dx[pos];
			yy=yy-len[j]*dy[pos];
		}pc('\n');
	}
	
	return 0;
}