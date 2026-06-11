#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define fix(n) cout<<fixed<<setprecision(n)
#define co(n) cout<<n<<endl
#define all(n) (n).begin(),(n).end()
using namespace std;
typedef long long ll;
const ll mod=1000000007;
double pi=3.1415926535;

int main(){
  int a,b,k;
  cin>>a>>b>>k;
  rep(i,1,k+1){
    if(i%2==1){
      if(a%2==0){
        b+=a/2;
        a/=2;
      }
      else{
        a--;
        b+=a/2;
        a/=2;
      }
    }
    else{
      if(b%2==1){
        b--;
        a+=b/2;
        b/=2;
      }
      else{
        a+=b/2;
        b/=2;
      }
    }
  }
  co(a<<" "<<b);

  return 0;
}