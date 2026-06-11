#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n; cin>>n;
  vector<int> v(n);
  rep(i,n){cin>>v[i];}
  sort(v.begin(),v.end());
  int i=0,c=1,ans=0;
  while(i<n){
    if(v[i]!=v[i+1]){
      if(c<v[i]){ans+=c;}
      if(c>v[i]){ans+=c-v[i];}
      c=1;i++;
    }
    while(v[i]==v[i+1]){i++;c++;}
  }
  cout<<ans<<endl;
}

