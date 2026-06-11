#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<tuple<string,int,int>> vec(n+1);
  for(int i=1;i<=n;i++){
    string s;cin>>s;
    int p;cin>>p;
    p=-p;
    vec[i]=make_tuple(s,p,i);
  }
  sort(all(vec));
  for(int i=1;i<=n;i++){
    string s;
    int p;
    int a;
    tie(s,p,a)=vec[i];
    cout<<a<<endl;
  }
}
    