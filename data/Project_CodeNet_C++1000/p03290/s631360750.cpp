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
  int n,m,c=0,d=0,ans=100000000,r=1; cin>>n>>m;
  rep(i,0,n) r*=2;
  vector<int> pro(n),sco(n);
  rep(i,0,n) cin>>pro[i]>>sco[i];
  rep(i,0,r){
    c=0; d=0; 
    int a=i,b=i;
    rep(i,0,n){
      if(a%2==1){
        c+=100*(i+1)*pro[i];
        c+=sco[i];
        d+=pro[i];
      }
      a/=2;
    }
    if(c>=m){ans=min(ans,d); continue;}
    rep(i,0,n){
      if(b%2==0){
        int x=m-c;
        if(x-100*(i+1)*(pro[i]-1)>0){b/=2; continue;}
        d+=(x+99)/(100*(i+1));
        ans=min(ans,d);
      }
      b/=2;
    }
  }
  co(ans);
  
  return 0;
}