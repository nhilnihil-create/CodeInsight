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
  int a,b,c;
  cin>>a>>b>>c;
  if(a<c && c<b) co("Yes");
  else if(b<c && c<a) co("Yes");
  else co("No");
  
  return 0;
}