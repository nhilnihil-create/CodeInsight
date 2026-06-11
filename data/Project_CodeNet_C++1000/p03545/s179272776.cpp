#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  
  vector<int> vec(4);
  vec.at(3) = t / 1000;
  vec.at(2) = (t - vec.at(3)*1000) / 100;
  vec.at(1) = (t - vec.at(3)*1000 - vec.at(2)*100) / 10;
  vec.at(0) = t - vec.at(3)*1000 - vec.at(2)*100 - vec.at(1)*10;
  
  vector<char> op(3);
  
  for(int i=0; i<(1 << 3); i++){
    int sum = vec.at(3);
    bitset<3> o(i);
    for(int j=2; j>=0; j--){
      if(o.test(j)){
        sum += vec.at(j);
        op.at(j) = '+';
      }else{
        sum -= vec.at(j);
        op.at(j) = '-';
      }
    }
    if(sum == 7){
      cout << vec.at(3);
      for(int k=2; k>=0; k--){
        cout << op.at(k) << vec.at(k);
      }
      cout << '=' << sum << endl;
      break;
    }
  }
}