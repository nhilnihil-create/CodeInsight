#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int p[n];
  rep(i,n){
    cin >> p[i];
  }
  
  sort(p,p+n,greater<int>());
  p[0] /= 2;
  int sum = 0;
  rep(i,n){
    sum += p[i];
  }
  
  cout << sum << endl;
}