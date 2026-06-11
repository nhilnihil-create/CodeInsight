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
  int a,b;
  int count = 0;
  cin >> a >> b;
  string s;
  cin >> s;
  for(int i=0;i<a;i++){
    if(s.at(i)=='0'||s.at(i)=='1'||s.at(i)=='2'||s.at(i)=='3'||s.at(i)=='4'||s.at(i)=='5'||s.at(i)=='6'||s.at(i)=='7'||s.at(i)=='8'||s.at(i)=='9')count++;
  }
  if(s.at(a)=='-')count++;
  for(int i=a+1;i<a+b+1;i++){
    if(s.at(i)=='0'||s.at(i)=='1'||s.at(i)=='2'||s.at(i)=='3'||s.at(i)=='4'||s.at(i)=='5'||s.at(i)=='6'||s.at(i)=='7'||s.at(i)=='8'||s.at(i)=='9')count++;    
  }
  if(count == a+b+1) cout<<"Yes"<<endl;
  else cout << "No"<<endl;
}