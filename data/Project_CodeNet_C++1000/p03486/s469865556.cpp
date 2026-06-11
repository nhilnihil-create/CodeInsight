// sort(b.begin(), b.end());//bという配列を小さい方からソート
//reverse(b.begin(), b.end());//bという配列を逆にソート 
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
  string s,t;
  cin >> s >> t;
  vector<int>a(s.size());//s.size);
  vector<int>b(t.size());//t.size);
  rep(i,s.size()) a.at(i) = s.at(i);
  rep(i,t.size()) b.at(i) = t.at(i);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());//bという配列を小さい方からソート
  reverse(b.begin(), b.end());//bという配列を逆にソート 
//  rep(i,s.size()) cout<< a.at(i) <<endl;
//  rep(i,t.size()) cout<< b.at(i) <<endl;
  int flag=0;
  int itticount=0;
  if(s.size() > t.size() ){
    for(int i=0; i < t.size() ; i ++){
      if(a.at(i) < b.at(i) ){
        flag = 1;
        break;
      }
      if(a.at(i) == b.at(i) ){
        itticount ++;
      }
    }//forend     
    if(itticount == s.size() && itticount == t.size() ) flag=0;
//    else if(itticount == t.size() ) flag=1;
  }//ifend
  else{
    for(int i=0; i < s.size() ; i ++){
      if(a.at(i) < b.at(i) ){
        flag = 1;
        break;
      }
      if(a.at(i) == b.at(i) ){
        itticount ++;
      }
    }//forend
    if(itticount == s.size() && itticount == t.size() ) flag=0;
    else if(itticount == s.size() ) flag=1;
  }//elseend
  if(flag==1) cout<<"Yes"<<endl;
  else cout << "No"<<endl;
}