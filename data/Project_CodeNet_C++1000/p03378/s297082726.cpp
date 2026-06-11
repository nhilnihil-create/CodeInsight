#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n,m,x;
  cin >> n >> m >> x;
  vector<int> a(n+1);
  rep(i,m){
    int x;
    cin >> x;
    a[x]++;
  }
  int ans1=0,ans2=0;
  rep(i,x-1) ans1+=a[i+1];
  rep(i,n-x-1) ans2+=a[x+i+1];
    
  cout << min(ans1,ans2);
  return 0;
}