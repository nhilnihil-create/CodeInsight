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
//10の1/2乗（ルート）pow(10, 0.5)
/*string s; stringでの文字列を数字型に変える方法
  cin >> s;
  rep(i,s.size()-2) {
  int a= (s.at(i)-'0')*100 + (s.at(i+1)-'0')*10+ s.at(i+2) -'0';
    */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  int a, b;
  cin >> a >> b;
  int sum = 0;
  for(int i=1;i<=n;i++){
    int num=0;
    if(i / 10 == 0){
      num = i;
    }
    else if(i / 100 == 0){
      num += i / 10;
      num += i % 10;
    }
    else if(i / 1000 == 0){
      int k = i;
      num += k / 100;
      k = k%100;
      num += k / 10;
      k = k%10;
      num += k;
    }
    else if(i / 10000 == 0){
      int k = i;
      num += k / 1000;
      k = k%1000;
      num += k / 100;
      k = k%100;
      num += k / 10;
      k = k%10;
      num += k;
    }
    else{
      num = 1;
    }
    if(a <= num && num <= b) sum += i;
  }
  cout << sum << endl;
}