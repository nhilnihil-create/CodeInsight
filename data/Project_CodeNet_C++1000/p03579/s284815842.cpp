#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MAX=1e5+5;

int N,M;
vi G[MAX];

int col[MAX];
bool dfs(int v,int c){
	col[v]=c;
	rep(i,sz(G[v])){
		if(col[G[v][i]]==c)return false;
		if(col[G[v][i]]==0 && !dfs(G[v][i],-c))return false;
	}
	return true;
}

int main(){
	cin>>N>>M;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if(dfs(0,1)){
		int w=0;
		rep(i,N)if(col[i]==1)w++;
		ll ans=(ll)w*(N-w);
		ans-=M;
		cout<<ans<<endl;
		
	}
	else{
		ll ans=(ll)N*(N-1)/2;
		ans-=M;
		cout<<ans<<endl;
	}
}