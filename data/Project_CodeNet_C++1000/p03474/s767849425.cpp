#include <iostream>
#include <string>

using namespace std;

int main() {

  int n, m, ans = 0, isB = 0;
  string p;
  cin >> n >> m >> p;
  for(int i = 0;i < p.size();i++){
    if(p[i] == '-'){
      if(!(ans == n)){
        cout << "No";
        return 0;
      }
      ans = 0;
    }else if('0' <= p[i] && p[i] <= '9'){
      ans++;
    }else{
      cout << "No";
      return 0;
    }
  }
  if(ans == m){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}
