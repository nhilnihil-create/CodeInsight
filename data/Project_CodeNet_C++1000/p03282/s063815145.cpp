//s.empty() //emptyなら1を出力 入っていれば0を出力
/*//ABC018-B 部分的にreverseをかける解法
int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>b(n);
  rep(i,n) cin>>a.at(i)>>b.at(i);
  rep(i,n)a.at(i)--;
  rep(i,n)b.at(i)--;
  string t;
  rep(i,n){
    t = s;
    for(int k=0;k<=b.at(i)-a.at(i);k++){
      t.at(a.at(i)+k) = s.at(b.at(i)-k);
    }
    s = t;
  }
  cout << s << endl;
}
*///ABC018-B
//  string s;
//  cin >> s;
//  cout << s.at(0) <<endl;
//  cout << s.at(0)-'0' <<endl;
//  Aが16？
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
  string s;
  cin >> s;
  ll k;
  cin >> k;
  ll num = 0;
  ll tmp = 1;
  k = k - 1;
  for(int i=0;i<s.size();i++){
    if(s.at(i)!='1'){
      num = i;
      tmp = s.at(i)-'0';
      break;
    }
  }
//  cout << num << endl;
//  cout << tmp << endl;
 	     if(k==0) 	cout<<s.at(0)<<endl;
    else if(k<num) 	cout<<s.at(0)<<endl;
    else			cout << tmp << endl;
}    