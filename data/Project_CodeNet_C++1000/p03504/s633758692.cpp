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
      int s,t,c;
      tie(s,t,c)=a.at(i);
      if((g<s&&h!=c)||(g<=s&&h==c)){
        f=s;
        g=t;
        h=c;
        e.at(i)=false;
        co++;
      }
    }
  }
  }
  
  cout<<ans<<endl;
}