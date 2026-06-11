#include<bits/stdc++.h>
using namespace std;

int main() {
  int num;
  int cnt = 1;
  int all = 0;
  cin >> num;
  
  vector<int> vec(num);
  for(int i = 0; i < num; i++) cin >> vec.at(i);
  
  for(int i = 0; i < num; i++){
    if(vec.at(i) % 2 == 0){
      cnt *= 2;
    }else{
      cnt *= 1;
    }
  }
  all = pow(3, num);

  cout << all -cnt;
}
