#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(I,0,n){cout<<(I ? " ":"")<<A[I]x;}cout<<endl;
#define pprint(A,y,m,n) rep(J,0,m){print(A[J],y,n);}
const long mod=998244353;
const int size=3e5+1;
const int inf=1e9;
int main(){
	int N,M; string s; cin>>N>>M>>s;
    vector<int> g[N];
	int cnt[N][2] = {};
	int a,b;
	rep(i,0,M){
		cin>>a>>b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
		cnt[a][s[b] - 'A']++;
		cnt[b][s[a] - 'A']++;
	}
	set<int> st; deque<int> dq;
	rep(i,0,N)if(cnt[i][0] == 0 || cnt[i][1] == 0) dq.push_back(i);
	int v;
	while(!dq.empty()){
		v = dq.front(); dq.pop_front();
		st.insert(v);
		for(int u:g[v]){
			if(!st.count(u)){
				cnt[u][s[v] - 'A']--;
				if(cnt[u][s[v] - 'A'] == 0) dq.push_back(u);
			}
		}
	}
	if(st.size() < N) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}