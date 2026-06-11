#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector <int> vec_d(n);
  
  for(int i= 0; i < n; i++){
    cin >> vec_d.at(i);
  }
  sort(vec_d.begin(),vec_d.end());
  vec_d.erase(unique(vec_d.begin(), vec_d.end()),vec_d.end());
  
  cout << vec_d.size() <<endl;  
}