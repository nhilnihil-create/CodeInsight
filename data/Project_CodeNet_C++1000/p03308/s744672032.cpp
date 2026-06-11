#include <bits/stdc++.h>

using namespace std;

int main(){
  
  int N;
  cin >> N;
  
  vector<long long> v(N);
  
  for(int i = 0; i < N; i++){
    long long x;
    cin >> x;
    v[i] = x;
  }
  sort (v.begin(),v.end());
  
  auto i = v.begin();
  auto j = v.end() - 1;
  
  cout <<abs(*j - *i);
}