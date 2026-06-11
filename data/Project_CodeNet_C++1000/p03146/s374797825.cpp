#include <bits/stdc++.h>
using namespace std;
int f(int n){
    if(n % 2 == 0){
        return n / 2;
    }
    else{
        return 3 * n + 1;
    }
}
int main(void){

  int s,k,i=1;
  cin >> s;
  vector<int> vec;
  vec.push_back(s);
  
  while(1){
      k = f(s);
      i++;
      if(count(vec.begin(),vec.end(),k) != 0) break;
      vec.push_back(k);
      s = k;
      
  }
  
  cout << i << endl;
}