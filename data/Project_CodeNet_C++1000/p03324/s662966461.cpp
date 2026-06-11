#include <bits/stdc++.h>
using namespace std;

int main(){
  int d, n;
  cin >> d >> n;
  
  int num = pow(100, d);
  vector<int> ans;
  for (int i=1 ; ; i++){
    if (i%num == 0 && i%(num*100) != 0){
      ans.push_back(i);
      if (ans.size() == n){
        cout << i << endl;
        break;
      }
    }
  }
}