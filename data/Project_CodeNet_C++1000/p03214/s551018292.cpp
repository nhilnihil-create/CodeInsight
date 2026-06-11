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
  int n,cc;
  double c=0,ans=100000000;
  cin>>n;
  int a[n];
  rep(i,0,n){
    cin>>a[i];
    c+=a[i];
  }
  c/=n;
  rep(i,0,n){
    if(ans>abs(c-a[i])){
      cc=i;
      ans=abs(c-a[i]);
    }
  }
  co(cc);
  
  return 0;
}