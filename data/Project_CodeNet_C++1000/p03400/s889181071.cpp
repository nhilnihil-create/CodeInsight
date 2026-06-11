#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int n, d, x;
  cin >> n >> d >> x;
  
  rep(i,n) {
    int a;
    cin >> a;
    x += (d+a-1)/a;
  }
  
  cout << x << endl;
}