//  cout << char(i+48) << endl;//なぜかaは47と得る時がある。+48で出力もaにできる。
//  cout << char(97) << endl;//アスキーコードでaを出力
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
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  vector<int> a(3);
  cin >> a.at(0);
  cin >> a.at(1);
  cin >> a.at(2);
  sort(a.begin(),a.end());
  int n = a.at(2) - a.at(0);
  int m = a.at(2) - a.at(1);
  if(n%2 ==0 && m%2==0){//ryouhouguusuu
    cout << n/2 + m/2 << endl;
  }
  else if(n%2 ==1 && m%2==1){
    cout << (n+m)/2 << endl;
  }
  else{
    cout << n/2 + m/2 + 2 << endl;
  }
//  cout << n << endl;
//  cout << m << endl;
}