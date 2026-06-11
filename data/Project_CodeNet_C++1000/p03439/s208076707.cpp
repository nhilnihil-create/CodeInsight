#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  int l=0,r=N+1;
  string T;
  puts("0");
  fflush(stdout);
  cin>>T;
  if(T=="Vacant")return 0;
  while(r-l>1){
    int n=(l+r)/2;
    cout<<n<<endl;
    fflush(stdout);
    string S;
    cin>>S;
    if(S=="Vacant")return 0;
    if((S!=T && (n-l)%2==1) || (S==T && (n-l)%2==0)){
      l=n;
      T=S;
    }
    else r=n;
  }
  cout<<l<<endl;
}