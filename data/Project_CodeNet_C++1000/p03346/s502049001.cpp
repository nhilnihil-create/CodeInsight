    #include<iostream>
    #include<stdio.h>
    //#include <bits/stdc++.h>
    #include<vector>
    #include<float.h>
    #include<iomanip>
    #include<algorithm>
    #include<string>
    #include<cstring>
    #include<math.h>
    #include<cmath>
    #include<sstream>
    #include<set>
    #include<map>
    #include<queue>
    #include<cassert>
    #include<cmath>
    #include<cstdint>
     
    #define INF 1e18
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
    #define ALL(a)  (a).begin(),(a).end()
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
     
const int MOD = 1e9 + 7;

class UnionFind {
    public : 

        vector<int> par;

        UnionFind(int N){
            par = vector<int>(N, -1);
        }

        int parent(int x){
            return par[x];
        }

        int root(int x){
            if(par[x] < 0)return x;
            return par[x] = root(par[x]);
        }

        int size(int x){
            return -par[root(x)];
        }

        void connect(int x, int y){
            int rx = root(x);
            int ry = root(y);
            if(rx == ry)return;

            if(size(rx) < size(ry))swap(rx, ry);

            par[rx] += par[ry];
            par[ry] = rx;

            return;
        }

        bool same(int x, int y){
            return root(x) == root(y);
        }
};


int main(){
   int n;
   cin >> n;
   vector<int> a(n);
   rep(i, n)cin >> a[i];

   UnionFind uf(n + 1);
   vector<bool> seen(n + 1, false);
   rep(i, n){
      if(seen[a[i] - 1])uf.connect(a[i], a[i] - 1);
      seen[a[i]] = true;
   }
   int res = 0;
   rep(i, n){
      res = max(res, uf.size(i));
   }
   cout << n - res << endl;
}
