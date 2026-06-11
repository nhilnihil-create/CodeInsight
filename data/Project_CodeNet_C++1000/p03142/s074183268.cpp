#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 100005;
int n, m, a, b, pn[MX], ans[MX];
vector<int> G[MX];
stack<int> st;
int main(){
	scanf("%d%d", &n, &m);
	rep(i,n+m-1){
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		pn[b]++;
	}
	rep(i,n) if(!pn[i+1]) st.push(i+1);
	while(!st.empty()){
		a = st.top(); st.pop();
		for(int nx: G[a]) if(!--pn[nx]){
			ans[nx] = a;
			st.push(nx);
		}
	}
	rep(i,n) printf("%d\n", ans[i+1]);
}