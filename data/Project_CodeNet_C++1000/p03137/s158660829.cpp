#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main(){
  int n,m;
  cin >>n>>m;
  int a[m];
  rep(i,m)cin >> a[i];
  sort(a,a+m);
  priority_queue<int> p;
  rep(i,m-1){
    p.push(a[i+1]-a[i]);
  }
  int ans=a[m-1]-a[0];
  for(int i=n;i>1;i--){
    if(p.empty()){cout << 0 << endl; return 0;}
    ans-=p.top();
    p.pop();
  }
  cout << ans << endl;
}