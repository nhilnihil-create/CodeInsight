#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=1e9+7;
const int size=1e5+1;
const long inf=1e14;
int u = 1;
vector<int> g[size];
vector<int> h[size];
void dfs(int v, int c){
	for(int t:g[c]){
		u++;
		h[v].push_back(u);
		dfs(u, t);
	}
}
int main(){
	string s; cin>>s;
	int n = s.size();
    rep(i,0,n-1)if(s[i] != s[n-2-i]){ cout<<-1<<endl; return 0; }
    if(s[0] == '0' || s[n-1] == '1'){ cout<<-1<<endl; return 0; }
    s[n-1] = '1';
	set<int> st; int j = 1;
	rep(i,2,n+1){
		if(s[i-1] == '0') continue;
		g[i].push_back(j);
        rep(k,0,i-1-j) g[i].push_back(1);
        j = i;
	}
	for(int v:st){
		if(st.count(n - v)){ cout<<-1<<endl; return 0; }
	}
	dfs(1, n);
	rep(i,1,n+1){
		for(int j:h[i]) cout<<i<<" "<<j<<endl;
	}
}