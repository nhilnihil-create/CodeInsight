#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 50;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

int color[205];
int dist;
int d[205][205];
vector<vector<int>>g;
int n;

bool dfs(int v,int c){
    color[v]=c;
    for(auto x:g[v]){
        if(color[x]==c)return false;
        if(color[x]==0&&!dfs(x,-c))return false;
    }
    return true;
}

//ワーシャルフロイド法、全点対最短路
const int INFTY=100000;

void warshall_floyd(int V){//Vは頂点数
	for(int k=0;k<V;++k){//経由する頂点
		for(int i=0;i<V;++i){//始点となる頂点
			for(int j=0;j<V;++j){
                //目的地の頂点
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
		}
	}
}


void solve(){
    ll a,b,k;
    cin>>a>>b>>k;
    rep(i,k){
        if(i%2==0){
            if(a%2)a--;
            b+=a/2;
            a/=2;
        }
        else {
            if(b%2)b--;
            a+=b/2;
            b/=2;
        }
    }
    cout<<a<<" "<<b<<endl;
}

signed main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	solve();
	return 0;
}
