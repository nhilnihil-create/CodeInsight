#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 110000000000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,ll> P;

int N;
vector<int> V[110000];
int color[110000];

//二部グラフならtrueを返す
bool dfs(int x,int c){
  color[x]=c;
  for(int i=0;i<V[x].size();i++){
    //隣接している頂点が同じ色ならfalse
    if(color[V[x][i]]==c) return false;
    //隣接している頂点がまだ塗られていないなら-cで塗る
    if(color[V[x][i]]==0 && !dfs(V[x][i],-c)) return false;
  }
  return true;
}


int main(){
    int M,a,b;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        a--; b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    if(dfs(0,1)){
        int count=0;
        for(int i=0;i<N;i++){
            if(color[i]==1) count++;
        }
        cout<<(ll)count*(N-count)-M<<endl;
    }else{
        cout<<(ll)N*(N-1)/2-M<<endl;
    }
}
