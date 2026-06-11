#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
 
#define rep(n) for(int i = 0; i < n; i++)
 
using namespace std;
 
int main () {
  long long N; cin >> N;
  vector<long long> a;
 
  rep(N) {
    long long b; cin >> b;
    a.push_back(b);
  }
 
  vector<long long> v;
  vector<long long> va;
 
  rep(N) {
    v.push_back(a[i] - (i + 1));
  }
 
  sort(v.begin(), v.end());
 
  int cet;
 
  if(N%2 != 0) {
    cet = v[(N - 1) / 2];
  } else {
    cet = (v[N / 2] + v[(N - 2) / 2]) / 2;
  }
 
 
  rep(N) {
    va.push_back(abs(a[i] - (i + 1 + cet)));
  }
 
  long long j = 0;
    rep(N) {
    j += va[i];
  } 
  
  cout << j << endl;

}