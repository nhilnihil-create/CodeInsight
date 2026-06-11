#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i,n){
    cin >> h.at(i);
  }
  vector<int> p(n);
  rep(i,n){
    p.at(h.at(i)-1)++;
  }
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  int ans=0;
  for(int i=k;i<n;i++){
    ans+=p.at(i);
  }
  cout << ans;
}