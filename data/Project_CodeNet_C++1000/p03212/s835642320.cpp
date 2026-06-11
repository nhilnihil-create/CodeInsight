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

int ans=0;
void dfs(ll n,ll m){
  if(n>m) return;
  vector<int> c(10);
  ll x=n;
  while(x>0){
    c[x%10]++;
    x/=10;
  }
  if(c[3]>0 && c[5]>0 && c[7]>0) ans++;
  dfs(n*10+3,m);
  dfs(n*10+5,m);
  dfs(n*10+7,m);
  return;
}

int main(){
  ll m,n=0;
  cin>>m;
  dfs(n,m);
  co(ans);
  
  return 0;
}