#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin>>n>>q;
  
  string s;
  cin>>s;
  
  int A[n+1];
  A[0]=0;
  for(int i=1;i<n;i++){
    if(s[i-1]=='A' && s[i]=='C') A[i]=A[i-1]+1;
    else A[i]=A[i-1];
  }
  A[n]=A[n-1];
  
  int l,r;
  int ans;
  rep(i,q){
    cin>>l>>r;
    if(r<n && s[r-1]=='A' && s[r]=='C') ans=A[r]-A[l-1]-1;
    else ans=A[r]-A[l-1];
    cout<<ans<<endl;
  }
    
  return 0;
}