// sort(b.begin(), b.end());//bという配列を小さい方からソート
// reverse(b.begin(), b.end());
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
  int64_t n,x;
  cin >> n >>x;
  vector<int64_t>a(n);
  rep(i,n) cin >> a.at(i);
  vector<int64_t>b(n);
  rep(i,n) b.at(i) = abs(x - a.at(i) );
  sort(b.begin(), b.end());//bという配列を小さい方からソート
  reverse(b.begin(), b.end());
//  rep(i,n) cout<<b.at(i) <<endl;
  int64_t k,t,s,r;
  k = 0; t = 0; s = 0; r = 0;
  
  k = b.at(0);
    for(int i=0;i<n-1;i++){
      t = b.at(i+1);
      if(k > b.at(i+1)){
        for(;;){
          s = k/t;
          r = k%t;
          if(r==0)break;
          k = t;
          t = r;          
        }//mugenend
        k = t;
      }//ifend
      else{
          for(;;){
          s = t/k;
          r = t%k;
          if(r==0)break;
          t = k;
          k = r;        
          }//mugenend
      }//elseend
    }//forend
    cout << k <<endl;

  
}