#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n;cin>>n;
  vector<pair<double, string>> v(n);
  double ans=0;
  rep(i,n){
    cin>>v.at(i).first>>v.at(i).second;
    double v1=v.at(i).first;
    string v2=v.at(i).second;
    if(v2=="JPY")ans+=v1;
    else{ans+=v1*380000;}
  }
  cout<<ans;            
}
      

