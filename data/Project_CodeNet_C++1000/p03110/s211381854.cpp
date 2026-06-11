#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  double x;
  string s;
  double ans=0;
  rep(i,n){
    cin>>x>>s;
    if(s=="JPY") ans+=x;
    else ans+=x*380000;
  }
  
  cout<< fixed << setprecision(15)<<ans<<endl;
    
  return 0;
}