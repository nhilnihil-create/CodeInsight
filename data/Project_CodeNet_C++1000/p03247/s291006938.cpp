#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define PB push_back
#define pii pair<int,int>
#define fir first
#define sec second
#define ll long long
#define MP make_pair
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=1010;
int sgn(int x) { return x>0?1:-1; }
int Abs(int x) { return x>0?x:-x; }
ll Xi[N],Yi[N];
int n;
vector<char> s[N];
char dy(int x) { return x>0?'U':'D'; }
char dx(int x) { return x>0?'R':'L'; }
int main() {
	rd(n);
	for(int i=1;i<=n;++i) rd(Xi[i]),rd(Yi[i]);
	int ty=((Xi[1]+Yi[1])%2+2)%2;
	for(int i=2;i<=n;++i) if(((Xi[i]+Yi[i])%2+2)%2!=ty) {
		printf("-1");
		return 0;
	}
	if(ty==0) {
		for(int i=1;i<=n;++i) {
			if(Abs(Xi[i])>Abs(Yi[i])) {
				s[i].PB(dx(Xi[i]));
				Xi[i]-=sgn(Xi[i]);
			}
			else {
				s[i].PB(dy(Yi[i]));
				Yi[i]-=sgn(Yi[i]);
			}
		}
	}
	for(int j=30;j>=0;--j)
		for(int i=1;i<=n;++i)
			if(Abs(Xi[i])>Abs(Yi[i])) {
				s[i].PB(dx(Xi[i]));
				Xi[i]-=sgn(Xi[i])*(1ll<<j);
			}
			else {
				s[i].PB(dy(Yi[i]));
				Yi[i]-=sgn(Yi[i])*(1ll<<j);
			}
	printf("%d\n",31+(!ty));
	if(!ty) printf("1 ");
	for(int j=30;j>=0;--j) printf("%d ",(1<<j));
	puts("");
	for(int i=1;i<=n;++i) {
		for(int j=0;j<s[i].size();++j) printf("%c",s[i][j]);
		puts("");
	}
	return 0;
}