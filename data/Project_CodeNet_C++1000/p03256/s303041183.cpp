#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a),ed=(b);i<=ed;++i)
typedef long long ll;
inline int read(){
    register int x=0,f=1;register char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}
    return f?x:-x; 
}

const int N=2e5+10;
int n,m,cnt[N][2],del[N];
vector<int> E[N];
char s[N];

inline void Dfs(int u){
    REP(i,0,E[u].size()-1){
	int v=E[u][i];
	--cnt[v][s[u]-'A'];
	if(!del[v]&&!cnt[v][s[u]-'A'])del[v]=1,Dfs(v);
    }
}

int main(){
    //freopen("in.in","r",stdin);
    n=read(),m=read();scanf("%s",s+1);
    REP(i,1,m){int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);++cnt[u][s[v]-'A'],++cnt[v][s[u]-'A'];}
    REP(i,1,n)if(!del[i]&&!(cnt[i][0]&&cnt[i][1]))del[i]=1,Dfs(i);
    REP(i,1,n)if(!del[i]){puts("Yes");return 0;}
    puts("No");
    return 0;
}
