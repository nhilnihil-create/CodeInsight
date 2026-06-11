#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
 
template <typename T>
struct UnionFind {
   vector<T> par; 
 
   UnionFind(T N) : par(N) { 
        for(T i = 0; i < N; i++) par[i] = i;
   }
 
   int root(T x) { 
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
   }
 
   void unite(T x, T y) { 
       T rx = root(x); 
       T ry = root(y); 
       if (rx == ry) return; 
       par[rx] = ry; 
   }
 
   bool same(T x, T y) { 
       T rx = root(x);
       T ry = root(y);
       return rx == ry;
   }
};
 
int main(){

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << c-(d-b) << " " << d+(c-a) << " " << (c-d+b)-(c-a) << " " << (d+c-a)-(d-b) << endl;


 
}