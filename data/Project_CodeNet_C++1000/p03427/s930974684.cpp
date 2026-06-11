//  s.at(0) = toupper(s.at(0));//小文字なら大文字へ//大文字の場合はそのまま
//  s.at(i) = tolower(s.at(i));//大文字なら小文字へ//小文字の場合はそのまま
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
ll kansuu(ll n){
  ll keta = 0;
  while(n>0){
    keta++;
    n/=10;
  }
  return keta;
}
ll kansuu2(ll n){
  ll kyu = 0;
  while(n>0){
    ll a = n%10;
    if(a==9)kyu++;
    n/=10;
  }
  return kyu;
}
ll kansuu3(ll n){
  ll wa = 0;
  while(n>0){
    wa += n%10;
    n/=10;
  }
  return wa;
}
ll kansuu4(ll keta){
  ll k=1;
  for(int i=1;i<=keta;i++){
    k = k * 10;
  }
  return k;
}

int main() {
  ll n;
  cin >> n;
  ll keta = kansuu(n);
  ll kyu = kansuu2(n);
  ll num = n/kansuu4(keta-1);
//  cout << keta<< endl;
//  cout << kyu << endl;
  if(n<=9){
      cout << n << endl;
      return 0;
  }
  else if(keta == kyu){
    cout << kansuu3(n)<<endl;
    return 0;
  }
  else if(keta-1 == kyu){
    ll num2 = n + 1;
    ll num3 = kansuu4(keta-1);
//    cout << num2 << endl;
//    cout << num3 << endl;
    if(num2 % num3 == 0){
      cout << num2/num3 -1 + 9*(keta-1) << endl;
//      cout <<"fda"<<endl;
      return 0;
    }
    else{
      cout << num-1+9*(keta-1)<<endl;
      return 0;
    }
  }
  else if(num == 1){
      cout <<9*(keta-1)<<endl;
      return 0;
      }
  else{
      cout << num-1+9*(keta-1)<<endl;
      return 0;
    }
}
