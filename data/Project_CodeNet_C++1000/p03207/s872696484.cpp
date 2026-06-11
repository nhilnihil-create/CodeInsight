#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
vector<int> input(int N) {
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  return vec;
}

int main() {
  int n;
  cin >> n;
  vector<int> v=input(n);
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  
  int sum=0;
  rep(i,n){
    sum += v[i];
  }
  cout << sum+v[0]/2 << endl;
}
