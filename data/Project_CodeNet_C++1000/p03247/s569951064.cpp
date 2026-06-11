#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
#define gc getchar
#define pc putchar
#define cs const
#define int ll

inline
int getint(){
	re int num;
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
	if(a<0)pc('-'),a=-a;
	while(a)ch[++ch[0]]=a-a/10*10,a/=10;
	while(ch[0])pc(ch[ch[0]--]^48);
}

cs ll INF=9223372036854775807L;
cs int N=1005;
cs ll dx[4]={1,-1,0,0};
cs ll dy[4]={0,0,-1,1};
cs char s[4]={'R','L','D','U'};

int n;
ll x[N],y[N];
vector<ll> len;
bool flag;

signed main(){
	n=getint();
	for(int re i=1;i<=n;++i){
		x[i]=getint(),y[i]=getint();
		if(i==1)flag=(x[i]+y[i])&1;
		else {
			if(flag!=((x[i]+y[i])&1))return puts("-1"),0;
		}
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
		ll xx=0,yy=0;
		for(int re j=0;j<len.size();++j){
			int pos=0;
			ll minn=INF;
			for(int re k=0;k<4;++k){
				ll tmpx=xx+len[j]*dx[k];
				ll tmpy=yy+len[j]*dy[k];
				if(abs(tmpx-x[i])+abs(tmpy-y[i])<minn){
					minn=abs(tmpx-x[i])+abs(tmpy-y[i]);
					pos=k;
				}
			}
			pc(s[pos]);
			xx=xx+len[j]*dx[pos];
			yy=yy+len[j]*dy[pos];
		}pc('\n');
	}
	return 0;
}