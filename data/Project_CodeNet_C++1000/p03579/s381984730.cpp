#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
const int MAX=1e+5;
vector<int> g[MAX];
vector<int> check(MAX,-1);//1:black,0:white
int u;
bool dfs(int v){//O(E)
	rep(i,0,g[v].size()){
        u=g[v][i];
		if(check[u]!=-1){
			if(check[u]==check[v]) return false;
		}else{
			check[u]=check[v]^1;
			if(!dfs(u)) return false;
		}
	}return true;
}
int main(){
	long N,M;cin>>N>>M;
	int a,b;
	rep(i,0,M){
		cin>>a>>b;a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
    }
    check[0]=0;
    if(dfs(0)){
        long count=0;
        rep(i,0,N){
            if(check[i]) count++;
        }cout<<count*(N-count)-M<<endl;
    }else{
        cout<<N*(N-1)/2-M<<endl;
    }
}