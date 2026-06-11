#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int w,h,t,x,y,n;
vec v[500010];
int main(){
	cin>>h>>w>>n;
	FOR(i,1,n){
		getint(x),getint(y);
		v[x].pb(y);
	}
	t=1;
	FOR(i,2,h){
		FOR(j,0,SZ(v[i])-1) if (v[i][j]<=t) return cout<<i-1<<endl,0;
		bool ok=1;
		FOR(j,0,SZ(v[i])-1) if (v[i][j]==t+1) ok=0;
		if (ok) ++t;
	}
	cout<<h<<endl;
	return 0;
}