#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

int H,W,N,x,y;
int cmi[200020];
int main() {
	read(W,H,N);
	for(int i=1;i<=W;i++)cmi[i] = H+1;
	for(int i=0;i<N;i++){
		read(x,y);
		cmi[x] = min(cmi[x],y);
	}
	int cv = 1;
	for(int i=1;i<=W;i++){
		if(cmi[i] > cv)cv+=1;
		if(cmi[i] < cv){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<W<<endl;
	return 0;
}
