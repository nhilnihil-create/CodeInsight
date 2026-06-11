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
  int n,k;
  cin >> n>> k;
  vector<int>a(n);
  vector<int>b(n);
  int ri = 0;
  int rcount = 0;
  int count=0;
  int rc=0;
  rep(i,n) cin >> a.at(i);
  rep(i,n) b.at( a.at(i) - 1 )++;
  rep(i,n) if(b.at(i)!=0)count++;
  if(k>=count)cout<<"0"<<endl;
  else{
    sort(b.begin(), b.end());
    for(;;){
      if(b.at(ri)!=0){
      rcount+=b.at(ri);
      rc ++;
      }
      if(k>=count - rc)break;
      ri ++;
    }
      cout << rcount <<endl;
  }
}