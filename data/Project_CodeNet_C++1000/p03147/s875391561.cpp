// sort(b.begin(), b.end());//bという配列を小さい方からソート
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
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h.at(i);
  int wa=0;
  rep(i,n) wa += h.at(i);
//  cout << wa <<endl;
  int mi = 1000;
  int miwa = 0;
  int i=0;
  for(;;){//mugenstart
    int b = 0;
    mi = 1000;
  for(int i=0;i<n;i++){
    if(h.at(i) == 0 ){
      for(int k=b; k<i;k++){
        mi = min(mi,h.at(k));
      }
      for(int k=b; k<i;k++){
       h.at(k) -= mi;
      }
      if(mi != 1000){
      wa -= mi * (i-b);
      miwa += mi;
      }
      b = i+1;
      mi = 1000;
    }//ifend
    else if(i == n-1){
      i++;
      for(int k=b; k<i;k++){
        mi = min(mi,h.at(k));
//        cout << "test"<< k << endl;
      }
//        cout << "最小値は"<< mi << endl;
      for(int k=b; k<i;k++){
       h.at(k) -= mi;
      }
      if(mi != 1000){
      wa -= mi * (i-b);
      miwa += mi;
      }
      b = i+1;
      mi = 1000;
    }//else if end
  }//for i end
  if(wa == 0)break;
  }//mugenend
  
/*  //2kaimawasudakenotameshi
    for(int i=0;i<n;i++){
    int b = 0;
    if(h.at(i) == 0 ){
      for(int k=b; k<i;k++){
        mi = min(mi,h.at(k));
      }
      for(int k=b; k<i;k++){
       h.at(k) -= mi;
      }
      wa -= mi * (i-b);
      miwa += mi;
      b = i+1;
    }//ifend
    else if(i == n-1){
      i++;
      for(int k=b; k<i;k++){
        mi = min(mi,h.at(k));
        cout << "test"<< k << endl;
      }
        cout << "最小値は"<< mi << endl;
      for(int k=b; k<i;k++){
       h.at(k) -= mi;
      }
      wa -= mi * (i-b);
      miwa += mi;
      b = i+1;
    }//else if end
  }//for i end

  //2kaimawasudakenotameshi
  */
//  cout << wa <<endl;
  cout << miwa <<endl;
//  rep(i,n) cout << h.at(i);
}