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
  
  int i;
  bool flag;
  int ans = 0;
  for(int i = A; i<=B; i++){
    string str = to_string(i);
    flag = 1;
    for(int j=0; j<str.size()/2; j++){
      if(str[j] != str[str.size()-1-j]){
	flag = 0;
	break;
      }
    }
    if(flag){
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
