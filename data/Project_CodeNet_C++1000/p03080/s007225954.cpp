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
  int n;
  string s;
  cin>>n>>s;
  int a=0,b=0;
  rep(i,0,n){
    if(s[i]=='R') a++;
    else b++;
  }
  if(a>b) co("Yes");
  else co("No");
  
  return 0;
}