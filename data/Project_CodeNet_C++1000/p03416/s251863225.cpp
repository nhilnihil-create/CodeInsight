#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

int main(){
  int A, B;
  cin >> A >> B;
  //入力終了
  
  int ans = 0;
  for(int i = A; i<=B; i++){
    //intをstringに変換
    string str = to_string(i), rev = str;
    //文字列の順列を逆にする
    reverse(rev.begin(), rev.end() );
    if(str == rev)
      ans++;
  }

  //解答
  cout << ans << endl;

  return 0;
}
