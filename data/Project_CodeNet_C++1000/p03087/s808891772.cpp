#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main(){
  int n,q;string s;cin>>n>>q>>s;
  vector<int> vec(n+1);
  rep(i,n){
    if(s[i]=='A'&&s[i+1]=='C')vec[i+1]=vec[i]+1;
    else vec[i+1]=vec[i];
  }
  rep(i,q){
    int l,r;cin>>l>>r;
    l--;r--;
    cout<<vec[r]-vec[l]<<endl;
  }
}