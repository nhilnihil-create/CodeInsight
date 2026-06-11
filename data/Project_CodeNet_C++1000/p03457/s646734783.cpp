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
  int n;
  cin >> n;
  vector<int>t(n+1);
  vector<int>x(n+1);
  vector<int>y(n+1);
  for(int i = 1;i<n+1;i++){
  cin >> t.at(i) >> x.at(i) >> y.at(i);
  }
  int flag=0;
  int kyori = 0;
  int time = 0;
  for(int i = 1;i<n+1;i++){
    kyori = abs(x.at(i)-x.at(i-1))+abs(y.at(i)-y.at(i-1));
    time =  abs(t.at(i)-t.at(i-1));
    if(kyori > time){
      flag = 1;
      break;
    }
    if(kyori%2 != time%2){
      flag = 1;
      break;
    }
  }
  if(flag==1) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}