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
  ll n,m,c=0; cin>>n>>m;
  vector<pair<int,int>> p(n);
  rep(i,0,n) cin>>p[i].first>>p[i].second;
  sort(all(p));
  rep(i,0,n){
    ll a=p[i].first,b=p[i].second;
    if(m>=b){c+=a*b; m-=b; continue;}
    c+=a*m; 
    break;
  }
  co(c);
  
  return 0;
}