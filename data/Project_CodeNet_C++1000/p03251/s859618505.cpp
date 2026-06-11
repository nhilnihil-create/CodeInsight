//vector<vector<int>> data(3, vector<int>(4));//int型の2次元配列(3×4要素の)の宣言
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
  int n,m,a,b;
  cin >> n >> m >> a >> b;
  vector<int>x(n);
  vector<int>y(m);
  
  rep(i,n) cin >> x.at(i);
  rep(i,m) cin >> y.at(i);
  
  int xma=-250;
  int ymi=+250;
  rep(i,n) xma = max(xma,x.at(i));
  rep(i,m) ymi = min(ymi,y.at(i));
  int flag=0;
  
  if(b-a >= 1){
    for(int i=a+1;i<=b;i++){
      if(xma < i && ymi >=i){
        cout << "No War"<<endl;
        flag =1;
        break;
      }
    }
  }
  if(flag==0) cout<<"War"<<endl;
}