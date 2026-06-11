#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;


int main(){
  int n,T;
  cin >> n >> T;
  vector<int> c(n);
  vector<int> t(n);
  rep(i,n) {
      cin >> c[i];
      cin >> t[i];
  }
  rep(i,n);
  int M =10000;
  rep(i,n){
      if(T>=t[i]){
          M=min(M,c[i]);
      }
  }
  if(M!=10000)cout << M << endl;
  else cout<< "TLE" << endl;
  }