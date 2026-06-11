#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
#define pb(n,m) n.push_back(m)
#define pi(n,m) n.insert(n.begin(),m);
#define ee(n) n.erase(n.end()-1)
#define eb(n) n.erase(n.begin())
using namespace std;
//using bint=boost::multiprecision::cpp_int;
typedef long long ll;
typedef unsigned long long ull;

int main(){
  int n,m=0,ans=0; cin>>n;
  vector<int> a(n+1);
  rep(i,0,n){
    cin>>a[i];
    m=max(m,a[i]);
  }
  a[n]=-1;
  rep(i,1,m+1){
    int c=0;
    bool f=false;
    rep(j,0,n+1){
      if(a[j]>=i) f=true;
      else if(f){
        ans++;
        f=false;
      }
    }
    ans+=c;
  }
  co(ans);
  return 0;
}