// sort(b.begin(), b.end());//bという配列を小さい方からソート
// reverse(b.begin(), b.end());//bという配列をリターン
// 10桁でdouble出力するパターン１ 
// printf("%.10f\n", ma);
// 10桁でdouble出力するパターン２
//cout << fixed << setprecision(10);
//  cout << ma << endl;

/*01 02 03 12 13 23　と６回見ていくパターン 
for(int i=0;i<n-1;i++){
  for(int j=i+1;j<n;j++){
    }
  }
*///vector<vector<int>> data(3, vector<int>(4));//int型の2次元配列(3×4要素の)の宣言
//int64_t a;
//10のi乗pow(10, i);
/*string s; stringでの文字列を数字型に変える方法
  cin >> s;
  rep(i,s.size()-2) {
  int a= (s.at(i)-'0')*100 + (s.at(i+1)-'0')*10+ s.at(i+2) -'0';
    */
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(3, vector<int>(n+1));//int型の2次元配列(3×4要素の)の宣言
  int summa=0;
  for(int i=1;i<=n;i++){
    cin >> a.at(1).at(i);   
  }
  for(int i=1;i<=n;i++){
    cin >> a.at(2).at(i);   
  }
      
  for(int i=1;i<=n;i++){
  int sum=0;
    for(int j=1;j<=i;j++){
      sum += a.at(1).at(j);
    }
    for(int j=i;j<=n;j++){
      sum += a.at(2).at(j);
    }
    summa = max(sum,summa);
  }
    cout << summa << endl;
}