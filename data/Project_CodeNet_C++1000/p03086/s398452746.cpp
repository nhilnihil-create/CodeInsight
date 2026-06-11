#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
#define pb(n,m) n.push_back(m)
#define fix(n) cout<<fixed<<setprecision(n);
using namespace std;
//using bint=boost::multiprecision::cpp_int;
typedef long long ll;
typedef unsigned long long ull;

int main(){
  string s; cin>>s;
  int c=0,ans=0;
  rep(i,0,s.size()){
    if(s[i]=='A' || s[i]=='C' || s[i]=='T' || s[i]=='G') c++;
    else{
      ans=max(ans,c);
      c=0;
    }
  }
  ans=max(ans,c);
  co(ans);
  
  return 0;
}