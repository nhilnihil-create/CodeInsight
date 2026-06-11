#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

class union_find {
public:
vector<int> par,rank,lsize;
union_find(int n): par(n),rank(n),lsize(n){
   for (int i=0;i < n;i++){
      par[i]=i;
      rank[i]=0;
      lsize[i]=1;
   }
}

int find(int x){
   if (par[x]==x){
      return x;
   }
   else{
      return par[x] = find(par[x]); 
   }
}

void unite(int x ,int y){
   x=find(x);
   y=find(y);
   if (x==y) return;
   if (rank[x] < rank[y]){
      lsize[y] += lsize[x];
      lsize[x] = -1;
      par[x] = y;
   }else{
      lsize[x] += lsize[y];
      lsize[y] = -1;
      par[y]=x;
      if (rank[x]==rank[y]) rank[x]++;
   }   
}

bool same(int x, int y){
   return find(x) == find(y);
}

int size(int x){
   if (lsize[x] == -1){
      x=find(x);
   }
   return lsize[x];
}
};

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    rep(i,n){
       cin >> v[i];
    }
    union_find tree(n);

    rep(i,m){
       int x,y;
       cin >> x >> y;
       x--;y--;
       tree.unite(x,y);
    }
    int ans = 0;
    rep(i,n){
       if (tree.same(i,v[i]-1)) ans++;
    }
    cout << ans << endl;

    
    return 0;

}