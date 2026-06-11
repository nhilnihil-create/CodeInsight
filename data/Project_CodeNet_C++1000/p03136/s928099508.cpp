#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;

int main(){
  int n; cin>>n;
  vector<int>L(n);
  rep(i,n) cin>>L[i];
  sort(L.begin(), L.end());
  int sum = 0;
  rep(i,n-1) sum += L[i];
  if (sum>L[n-1]) cout << "Yes" << endl;
  else cout << "No" << endl;
}