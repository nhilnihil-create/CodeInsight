#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<tuple<string,int,int>> tpl(n+1);
  for(int i=1;i<=n;i++){
    string s;int p;cin>>s>>p;
    p=-p;
    tpl[i]=make_tuple(s,p,i);
  }
  sort(all(tpl));
  for(int i=1;i<=n;i++){
    cout<<get<2>(tpl[i])<<endl;
  }
}