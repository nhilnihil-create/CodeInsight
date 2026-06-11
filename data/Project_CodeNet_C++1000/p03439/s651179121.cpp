#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
//main
signed main(){
  int N;cin>>N;
  string s,t;
  cout<<0<<endl;cin>>s;if(s=="Vacant")return 0;
  cout<<N-1<<endl;cin>>t;if(t=="Vacant")return 0;
  int l=0,r=N-1;
  for(int i=0;i<25;i++){
    int m=(r+l)>>1;
    cout<<m<<endl;string u;cin>>u;if(u=="Vacant")return 0;
    if(((m-l)&1)^(s!=u))r=m,t=u;
    else l=m,s=u;
  }
}
