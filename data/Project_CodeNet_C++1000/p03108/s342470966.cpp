#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

class UnionFindTree{
  public:
    vector<ll> rank,p,count;
    ll ans;

    UnionFindTree() {}

    UnionFindTree(ll size){
      rank.assign(size, 0);
      p.assign(size, 0);
      count.assign(size,1);
      REP(i,size)makeSet(i);
      ans = size * (size-1) / 2;
    }

    void makeSet(int x){
      p[x] = x;
      rank[x] = 0;
    }

    bool same(int x, int y){
      return findSet(x) == findSet(y);
    }

    void unite(int x, int y){
      if(findSet(x) == findSet(y))return;

      x = findSet(x);
      y = findSet(y);
      
      if(rank[x] > rank[y]){
        p[y] = x;
      }else{
        p[x] = y;
        if(rank[x] == rank[y]){
          rank[y]++;
        }
      }

      ans -= count[x] * count[y];
      ll tmp = count[x] + count[y];
      count[x] = tmp;
      count[y] = tmp;
    }

    int findSet(int x){
      if(x != p[x]){
        p[x] = findSet(p[x]);
      }
      return p[x];
    }

    void print(){
      REP(i,p.size()){
        cout << p[i] << " ";
      }
      cout << endl;
      REP(i,p.size()){
        cout << rank[i] << " ";
      }
      cout << endl;
    }

};



int main(){
  int n,m;
  cin >> n >> m;

  VI a(m),b(m);
  REP(i,m){
    cin>>a[i];
    cin>>b[i];
    a[i]--; b[i]--;
  }

  UnionFindTree tree(n);
  vector<ll> ans;
  for(int i = m-1; i >= 0; i--){
    ans.emplace_back(tree.ans);
    tree.unite(a[i], b[i]);
  }
  for(int i = m-1; i >= 0; i--){
    cout << ans[i] << endl;
  }
}

