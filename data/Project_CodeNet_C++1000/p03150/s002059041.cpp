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
int kan_hyaku(int n){
  int kurai = 0;
  for(int i=0;i<3;i++){
    kurai = n%10;
    n /=10;
  }
  return kurai;
}
int kan_ju(int n){
  int kurai = 0;
  for(int i=0;i<2;i++){
    kurai = n%10;
    n /=10;
  }
  return kurai;
}
int kan_ichi(int n){
  int kurai = 0;
  for(int i=0;i<1;i++){
    kurai = n%10;
    n /=10;
  }
  return kurai;
}
int main() {
  string t = "keyence*";
  string s;
  cin >> s;
  int count		= 0;
  int okflag	= 0;
  for(int i=0;i<7;i++){
    if(s.at(i) == t.at(i) ) count++;
  }
  if(count==7)okflag=1;
  count = 0;
  for(int i=0;i<7;i++){
    if(s.at(s.size()-7+i) == t.at(i))count++;
  }
  if(count==7)okflag=1;
  count=0;
  
  if(s.at(0) =='k'){
    for(int i=0;i<6;i++){
      if(s.at(s.size()-6+i) ==t.at(1+i))count++;
    }
    if(count==6)okflag=1;
    count=0;
  }
  
  if(s.at(0) =='k'&&s.at(1) == 'e'){
    for(int i=0;i<5;i++){
      if(s.at(s.size()-5+i) ==t.at(2+i))count++;
    }
    if(count==5)okflag=1;
    count=0;
  }
  
  if(s.at(0) =='k'&&s.at(1) == 'e' && s.at(2) =='y'){
    for(int i=0;i<4;i++){
      if(s.at(s.size()-4+i) ==t.at(3+i))count++;
    }
    if(count==4)okflag=1;
    count=0;
  }

  if(s.at(0) =='k'&&s.at(1) == 'e'&& s.at(2) =='y'&&s.at(3) =='e'){
    for(int i=0;i<3;i++){
      if(s.at(s.size()-3+i) ==t.at(4+i))count++;
    }
    if(count==3)okflag=1;
    count=0;
  }
  
  if(s.at(0) =='k'&&s.at(1) == 'e'&& s.at(2) =='y'&&s.at(3) =='e'&&s.at(4) =='n'){
    for(int i=0;i<2;i++){
      if(s.at(s.size()-2+i) ==t.at(5+i))count++;
    }
    if(count==2)okflag=1;
    count=0;
  }

  if(s.at(0) =='k'&&s.at(1) == 'e'&& s.at(2) =='y'&&s.at(3) =='e'&&s.at(4) =='n'&&s.at(5) =='c'){
    for(int i=0;i<1;i++){
      if(s.at(s.size()-1+i) ==t.at(6+i))count++;
    }
    if(count==1)okflag=1;
    count=0;
  }

  if(okflag==1)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  //test
  //  cout << okflag << endl;
  //test
}
