#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}

int main(){
  int n,z,w; cin >> n >> z >> w;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  if(n==1){
    cout << abs(a[0]-w) << endl;
  }else cout << max(abs(a[n-1]-w),abs(a[n-2]-a[n-1])) << endl;
  
  return 0;
}