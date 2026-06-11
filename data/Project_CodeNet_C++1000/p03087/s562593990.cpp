#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef vector<int> vec;

int main(){
  int n,q,l,r;cin>>n>>q;
  string s; cin>>s;
  
  int fac[n],bac[n];
  

  fac[0]=0;
  for(int i=1;i<n;i++){
    if(s[i-1]=='A'&&s[i]=='C')fac[i]=fac[i-1]+1;
    else fac[i]=fac[i-1];
  }
  bac[n-1]=0;
    for(int i=n-2;i>=0;i--){
    if(s[i]=='A'&&s[i+1]=='C')bac[i]=bac[i+1]+1;
    else bac[i]=bac[i+1];
  }

  rep(i,q){
    cin>>l>>r;
    cout<<fac[n-1]-(l>1?fac[l-1]:0)-(r<n?bac[r-1]:0)<<endl;
  
  }
}