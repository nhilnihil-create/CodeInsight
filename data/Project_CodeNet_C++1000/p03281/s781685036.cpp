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
  int n; cin>>n;
  int c=0;
  rep(i,105,n+1){
    int d=0;
    rep(j,1,i+1){
      if(i%j==0) d++;
    }
    if(d==8) c++;
    i++;
  }
  co(c);
  
  return 0;
}