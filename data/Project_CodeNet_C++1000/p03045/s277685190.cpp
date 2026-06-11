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
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<char,int>;


// UnionFind木(サイズ持ち)
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
   int n, m;
   cin >> n >> m;
   UnionFind uf(n);

   rep(i, m){
       int x, y, z;
       cin >> x >> y >> z;
       x--;y--;
       uf.connect(x, y);
   }

   map<int, int>mp;
   rep(i, n){
       mp[uf.root(i)]++;
   }
   int res = 0;
   for(auto m : mp)res++;
   cout << res << endl;
}

