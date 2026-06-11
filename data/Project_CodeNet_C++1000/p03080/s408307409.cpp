#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
ll MOD = 1000000007;
ll INF = 200000000000000000;
double EPS = 1e-12;
double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

struct UnionFind{
    vector<int> par;
    vector<int> rank;
    vector<ll> connection;

    UnionFind(int N):par(N),rank(N),connection(N){
        rep(i,N){
          par[i] = i;
          rank[i] = 0;
          connection[i] = 1;
        }
    }

    int root(int x){
       while(x != par[x]){
        x =  par[x] = par[par[x]];
       }
       return x;
    }
    
    bool same(int x,int y){
      return root(x) == root(y);
    }

    void unite(int x,int y){
        int rx = root(x);
        int ry = root(y);
        if(!same(x,y)){
            connection[root(x)] += connection[root(y)];
            connection[root(y)] = connection[root(x)];
        }
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

    ll SIZE(int x){
        return connection[root(x)];
    }
};


int main(){
  ll N;
  string S;
  cin >> N >> S;
  if(count(ALL(S),'R') >= (S.size())/2+1){
    cout <<"Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}