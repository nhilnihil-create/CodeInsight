#include <bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin >> n;

  int num;
  vector<int> v;

  for(int i; i<n; ++i){
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(),v.end());

  int ans = v.back() - v.front();
  cout << ans <<endl;

  return 0;
  
}