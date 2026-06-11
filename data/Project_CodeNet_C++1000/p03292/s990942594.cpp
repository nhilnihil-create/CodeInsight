#include<bits/stdc++.h>
using namespace std;

int main(){
 
  vector<int> v(3);
  
  for(int i = 0; i < 3; i++){
    int x;
    cin >> x;
    v[i] = x;
  }
  int sum = 0;
  sort(v.begin(),v.end());
  for(int i = 1; i < 3; i++){
    int t = abs(v[i] - v[i - 1]);
    sum += t;
  }
  cout << sum;
}
    
