#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,m;
  cin >> n >> m;
  if(n==1){
    cout << max(m-2,n);
    return 0;
  }
  if(m==1){
    cout << max(n-2,m);
    return 0;
  }
  cout << n*m-(2*n+2*m-4);
}
     