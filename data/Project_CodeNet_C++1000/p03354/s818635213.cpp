#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

struct Unionfind{
  vector<int> parents;
  int m;
  Unionfind(int n):parents(n,-1){
    m = n;
  }

  int find(int x){
    if(parents.at(x) < 0){
      return x;
    }else{
      parents.at(x) = find(parents.at(x));
      return parents.at(x);
    }
  }

  void unite(int x,int y){
    x = find(x);
    y = find(y);

    if(x==y) return;
    if(parents.at(x) > parents.at(x))swap(x,y);
    parents.at(x) += parents.at(y);
    parents.at(y) = x;
  }

  int size(int x){
    return -parents.at(find(x));
  }

  bool same(int x,int y){
    return find(x) ==find(y);
  }

  vector<int> members(int x){
    int root = find(x);
    vector<int> A;
    for(int i=0;i<m;i++){
      if(find(i) ==root ){
        A.push_back(i);
      }
    }
    return A;
  }
};

 
int main() {
  int n,m;
  cin >> n >> m;
  vector<int> p(n);
  rep(i,n){
    int a;
    cin >> a;
    --a;
    p.at(a) = i;
  }
  //rep(i,n) cout << p.at(i) << " " ;
  
  Unionfind uf(n);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    --a;--b;
    uf.unite(a,b);
  }
  
  int ans = 0;
  rep(i,n){
   if(uf.same(i,p.at(i))) ans ++;
  }
  
  cout << ans << endl;
  
  return 0;
}



