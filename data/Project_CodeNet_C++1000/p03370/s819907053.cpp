#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  int i, min=INT_MAX, N, X, v, sum;
  
  cin >> N >> X;
  
  rep(i,N){
    cin >> v;
    if(v<min)min=v;
    X -= v;
  }
  
 
  cout << N + X/min;
}





