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
  int a[4],t[4]={1,4,7,9},c=0;;
  rep(i,0,4) cin>>a[i];
  sort(a,a+4);
  rep(i,0,4) if(a[i]==t[i]) c++;
  if(c==4) co("YES");
  else co("NO");
  
  return 0;
}