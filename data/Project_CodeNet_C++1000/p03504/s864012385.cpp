#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int n,m;
  cin >> n>>m;
  vector<tuple<int,int,int>>a;
  
  rep(i,n){
    int s,t,c;
    cin>>s>>t>>c;
    a.push_back(tuple<int,int,int>(s,t,c));
  }
  sort(a.begin(),a.end());
  vector<bool>e(n,true);
  int ans=0;
  int co=0;
  while(co<n){
    ans++;
    int f=0;
    int g=0;
    int h=0;
  rep(i,n){
    if(e.at(i)){
      if((g<get<0>(a[i])&&h!=get<2>(a[i]))||(g<=get<0>(a[i])&&h==get<2>(a[i]))){
        f=get<0>(a[i]);
        g=get<1>(a[i]);
        h=get<2>(a[i]);
        e.at(i)=false;
        co++;
      }
    }
  }
  }
  
  cout<<ans<<endl;
}