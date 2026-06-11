#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> vec(4);
  vec[0] = N/1000;
  vec[1] = (N/100) % 10;
  vec[2] = (N%100) / 10;
  vec[3] = N%10;
  for(int i=0;(1<<3);i++){
    bitset<3> bit(i);
    int ans = vec[0];
    for(int j=0;j<3;j++){
      if(bit.test(j)) ans += vec[j+1];
      else ans -= vec[j+1];
    }
    if(ans == 7){
      cout << vec[0];
      for(int j=0;j<3;j++){
        if(bit.test(j)) cout << "+";
        else cout << "-";
        cout << vec[j+1];
      }
      cout << "=7" << endl;
      break;
    }
  }
}