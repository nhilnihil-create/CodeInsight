#include<bits/stdc++.h>

#define ll long long
const int inf = 1e9+7;
const ll INF = 1e18+7;

using namespace std;

int m,n;
ll a[1000][3];
vector<ll> ans;
void solve(int A , int b , int c){
  vector<ll> tmp;
  for(int i =0; i < n; ++i){
    tmp.push_back(A*a[i][0]+b*a[i][1]+ c*a[i][2]);
  }
  sort(tmp.begin(),tmp.end());
  ll X = 0;
  for(int i =0; i < m; ++i)
    X += tmp[n-i-1];
  ans.push_back(X);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >>m;
  for(int i = 0; i < n; ++i){
    cin>>a[i][0]>>a[i][1]>>a[i][2];
  }
  solve(1,1,1);
  solve(1,1,-1);
  solve(1,-1,1);
  solve(1,-1,-1);
  solve(-1,1,1);
  solve(-1,1,-1);
  solve(-1,-1,1);
  solve(-1,-1,-1);
  ll t = -1e11;
  for(ll x : ans)
    t = max(x,t);
  
  cout<<t<<"\n";
}
