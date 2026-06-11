#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, K, a=0;
  vector<int> devide_number;
  cin >> A >> B >> K;
  
  for(int i=1; i<=A; i++){
    if (A % i==0 && B % i==0){
      devide_number.push_back(i);
    }
  }
  
  a=devide_number.size();
  cout << devide_number.at(a-K) << endl;
}
