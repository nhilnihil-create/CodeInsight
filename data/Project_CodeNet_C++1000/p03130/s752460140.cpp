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
  int a[4]={},b=0,c=0;
  rep(i,0,6){
    cin>>b;
    a[b-1]++;
  }
  rep(i,0,4){
    if(a[i]==0 || a[i]==3){
      co("NO");
      break;
    }
    if(i==3) co("YES");
  }
  
  
  return 0;
}