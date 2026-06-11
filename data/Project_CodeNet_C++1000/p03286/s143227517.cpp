#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  if(n==0) cout<<0<<endl;
  else{
    vector<bool> v;
    while(n!=0){
      if(n%2==0){
        v.push_back(false);
        n=n/(-2);
      }
      else{
        v.push_back(true);
        n=(n-1)/(-2);
      }
    }
    reverse(v.begin(),v.end());
    rep(i,0,v.size()){
      if(v[i]) cout<<1;
      else cout<<0;
    }
    cout<<endl;
  }
}