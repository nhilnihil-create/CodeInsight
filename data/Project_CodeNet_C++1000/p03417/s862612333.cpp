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
  int64_t n,m;
  int64_t num;
  cin >> n >> m; 
  if(n==1 || m==1){
    if(n==1&&m==1)num=1;
    else if(n==1&&m>=3)num=m-2;
    else if(n==1&&m<3)num=0;
    else if(m==1&&n>=3)num=n-2;
    else if(m==1&&n<3)num=0;
    
  }
  else{
    num=(m-2) * (n-2);
  }
  if(num>=0)cout<<num<<endl;
  else cout<<0<<endl;
}
