#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <map>

//#define INF 100000000
//#define MOD (int) (1e9+7)
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

/*
const int MAX = 1000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

//テーブルの前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        //そのまま計算すると負の値になるのでMODを足す
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//UnionFind木
struct UnionFind{
   vector<long long int> par; //par[i] : iの親の番号
   vector<long long int> rnk; //root[i] : iの木のサイズ

   //コンストラクタ
   UnionFind(long long int n): par(n), rnk(n){
       //木の初期化
       for(long long int i = 0; i < n; i++){
           par[i] = i;
           rnk[i] = 1;
       }
   }

   //データxが属する木の根を再帰で取得
   long long int root(long long int x){
       if(par[x] == x){
           return x;
       }else{
           return par[x] = root(par[x]);
       }
   }

   //xとyが同じ木に属しているかを判定
   bool same(long long int x, long long int y){
       return root(x) == root(y);
   }

   //xとyの木を併合
   void unite(long long int x, long long int y){
       long long int rx = root(x); //xの根
       long long int ry = root(y); //yの根
       if(rx == ry) return; //根が同じならそのまま

       //併合するときにサイズを足し合わせる
       if(rnk[rx] < rnk[ry]){
           par[rx] = ry;
           rnk[ry] += rnk[rx];
       }else{
           par[ry] = rx;
           rnk[rx] += rnk[ry];
       }
   }

   //属している木のサイズを取得
   long long int size(long long int x){
       return rnk[root(x)];
   }
};
*/

int main(){
    int n;
    cin >> n;

    vector<long long int> v;

    long long int sum = 0;
    for(int i = 0; i < n; i++){
        long long int a, b;
        cin >> a >> b;
        sum -= b;
        v.push_back(a + b);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        if(i%2 == 0) sum += v[n-1-i];
    }

    cout << sum << endl;
}
