#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int N, A, B;
  bool flag;
  cin >> N >> A >> B;
  if(B-A == 1){
    cout << "Borys" << endl;
    return 0;
  }else{
    while(1){
      A++;
      if(B-A == 1){
        flag = true;
        break;
      }else{
        B--;
        if(B-A == 1){
          flag = false;
          break;
        }
      }
    }
  }
  if(flag){
    cout << "Alice" << endl;
  }else{
    cout << "Borys" << endl;
  }
  return 0;
}
