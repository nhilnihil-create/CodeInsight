#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  ll ans=0;
  rep(i,n){
    int x=v[i];
    ans+=x;
    for(int j=i;j<n;j++){
      if(v[j]>=x) v[j]-=x;
      else{
        x=v[j];
        v[j]=0;
      }
    }
  }
  cout << ans << endl;
}