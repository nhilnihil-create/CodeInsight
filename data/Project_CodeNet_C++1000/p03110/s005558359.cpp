#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main() {
  int n; 
  cin>>n;
  double ans=0;
  rep(i,n){
    double a;
    string b;
    cin>>a>>b;
    if(b=="JPY"){
      ans+=a;
    }
    else{
      ans+=a*380000.0;
    }
  }
  
  cout<<fixed<<setprecision(8);
  cout<<ans<<endl;
}