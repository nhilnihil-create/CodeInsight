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
  int64_t a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int64_t ap=0,bp=0,cp=0;
  
  //1枚ずつそれぞれ買う金額の合計
  ap = a * x + b * y;
  //枚数の少ない方にはハーフサイズで合わせて、残りをソロで買う方法
  if(x > y){
  bp =  c * y * 2;
  bp += a * (x-y);
  }
  else{
  bp =  c * x * 2;
  bp += b * (y-x);    
  }
  //cout << bp << endl;

  //ハーフサイズでそろえる
  if(x > y){
  cp = c * x * 2;
  }
  else{
  cp = c*y*2;  
  }
  if(ap <= bp && ap <= cp) cout<<ap<<endl;
  else if(bp <= ap && bp <= cp )cout<<bp<<endl;
  else cout<<cp<<endl;
}