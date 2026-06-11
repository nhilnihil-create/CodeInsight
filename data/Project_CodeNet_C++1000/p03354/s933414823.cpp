#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 90000000000000000;
int PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

struct UnionFind{
    vector<int> par;
    vector<int> rank;

    UnionFind(int N):par(N),rank(N){
        for(int i = 0;i < N;i++){
          par[i] = i;
          rank[i] = 0;
        }
    }

    int root(int x){
       while(x != par[x]){
        x =  par[x] = par[par[x]];
       }
       return x;
    }

    void unite(int x,int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry)return;
        if(rank[x] > rank[y]){
          par[y] = rx;
        }
        if(rank[x] < rank[y]){
          par[rx] = ry;
        }else{
          par[ry] = rx;
          if(rank[x] == rank[y]){
            rank[rx]++;
          }
        }
    }

    bool same(int x,int y){
      return root(x) == root(y);
    }
};


int main(){
  int N,M;cin >> N >> M;
  vector<int> P(N);
  for(int i = 0;i < N;i++){
    cin >> P[i];P[i]--;
  }
  UnionFind U(N);
  for(int i = 0;i < M;i++){
    int a,b;cin >> a >> b;
    a--;b--;
    U.unite(P[a],P[b]);
  }
  int ans = 0;
  for(int i = 0;i < N;i++){
    if(U.same(i,P[i])){
      ans++;
    }
  }
  cout << ans << endl;
}