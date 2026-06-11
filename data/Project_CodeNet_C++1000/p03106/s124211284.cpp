#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll a,b,k; cin >> a >> b >> k;
  vector<ll>A(0);
  rep(i,max(a,b)+1){
    if(i == 0){
      continue;
    }
    if(a%i == 0 && b%i == 0){
      A.push_back(i); 
    }
  }
  sort(A.begin(),A.end(),greater<ll>());
  cout << A[k-1];
}