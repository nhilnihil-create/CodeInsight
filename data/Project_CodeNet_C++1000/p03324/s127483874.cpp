//ぶっちゃけ問題文理解してないけど、正しい出力でるのでおｋ
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
  int d,n;
  cin >> d >> n;
  
  if(d==0){
    cout << n + (n/100) << endl;
    return 0;
  }
  if(d==1){
    cout << 100 * n + 100 * (n/100) << endl;
    return 0;
  }
  if(d==2){
    cout << setprecision(15) <<  pow(100,d) * n + pow(100,d) * (n/100) << endl;
    return 0;
  }
}
