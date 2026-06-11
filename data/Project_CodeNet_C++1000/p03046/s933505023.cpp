#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
#define PI 3.141592653589793
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
int gcd(int a, int b){//ユークリッドの互除法
  if (a < b) gcd(b,a); //aの方がbよりでかいのが前提
  if (b == 0) return a; //aをbで割り切れたらreturn
  else gcd(b, a % b);
}
const int INF = 1<<30;
const int MOD = 1000000007;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
  int m,k; cin >> m >> k;
  vector<int> v;
  int n = 1 << m;
  if(n <= k){
    puts("-1"); 
    return 0;
  }
  if(m == 1){
    if(k == 0){
      puts("0 0 1 1");
    }else{
      puts("-1");
    }
    return 0;
  }
  
  rep(i,n){
    if(i==k) continue;
    v.push_back(i);
  }
  auto v2 = v;
  reverse(v2.begin(),v2.end());
  
  v.push_back(k);
  v.insert(v.end(), v2.begin(), v2.end());
  v.push_back(k);
  
  for(auto x:v){
    cout << x << " ";
  }
  
  return 0;
}