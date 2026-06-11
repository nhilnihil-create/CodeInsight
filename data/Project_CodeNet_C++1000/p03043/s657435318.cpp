#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  double n,k; cin>>n>>k;
  double ans=0;
  // kの何分の1以上の範囲を示す
  double denom = 1;
  // 出た目がk以上ならば、無条件で勝利
  // そうでないときはコインを振る
  // k/2より大きい最小の整数~k-1までは,1/2の確率で勝つ
  // k/4より...と続ける？
  for(double i=n; i>=1; i--) {
    while(i<k/denom) denom*=2;
    ans+=1.0/(n*denom);
  }
  cout << fixed << setprecision(12) << ans << endl;
}
