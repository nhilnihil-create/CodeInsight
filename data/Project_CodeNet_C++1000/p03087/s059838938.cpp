#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

int main() {
  int n,q; cin>>n>>q;
  string s; cin>>s;
  vector<int> v(n,0);
  rep(i,n-1){
    v[i+1]=v[i];
    if(s.at(i)=='A'&&s.at(i+1)=='C'){v[i+1]++;}
    //cout<<v[i]<<" ";
  }
  rep(i,q){
    int l,r,ans; cin>>l>>r;
    if(l==1){ans=v[r-1];}
    else{
      ans=v[r-1]-v[l-2];
      if(s.at(l-2)=='A'&&s.at(l-1)=='C'){ans--;}
    }
    cout<<ans<<endl;
  }
}