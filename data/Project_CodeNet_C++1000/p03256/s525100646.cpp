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

int n,m;
char s[200020];
int u,v,rem[200020],cnt[200020][2];
vector<int> G[200020];

int main() {
	read(n);read(m);
	cin>>(s+1);
	for(int i=0;i<m;i++){
		read(u);read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int cr = n;
	queue<int> Q;
	for(int i=1;i<=n;i++){
		rem[i] = 1;
		for(auto ct:G[i]) cnt[i][s[ct]-'A']+=1;
		if(!cnt[i][0] || !cnt[i][1]){
			Q.push(i);
			rem[i] = 0;
		}
	}
	while(!Q.empty()){
		int cc = Q.front();Q.pop();
		cr-=1;
		for(auto ct:G[cc]){
			if(!rem[ct])continue;
			cnt[ct][s[cc]-'A']-=1;
			if(!cnt[ct][0] || !cnt[ct][1]){
				Q.push(ct);
				rem[ct] = 0;
			}
		}
	}
	if(cr){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
