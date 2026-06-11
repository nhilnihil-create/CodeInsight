#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i,n)cin >> a[i];
  int k=(n-1)/300+1;
  int u[k];
  int cnt=0;
  rep(i,k-1){
    u[i]=a[cnt];
    cnt++;
    rep(j,299){
      u[i]=gcd(u[i],a[cnt]);
      cnt++;
    }
  }
  u[k-1]=a[cnt];
  cnt++;
  while(cnt<n){
    u[k-1]=gcd(u[k-1],a[cnt]);
    cnt++;
  }
  int ans=0;
  rep(i,n){
    int t=i/300;
    int y;
    if(t!=0){
      y=u[0];
      rep(j,k-1){
        if(j+1!=t)y=gcd(y,u[j+1]);
        else{
          rep(l,300){
            if(300*(j+1)+l>=n)continue;
            if(300*(j+1)+l==i)continue;
            y=gcd(y,a[300*(j+1)+l]);
          }
        }
      }
      ans=max(ans,y);
    }
    else{
      int f=0;
      rep(q,n){
        if(q==i)continue;
        if(f==0)f=a[q];
        else f=gcd(f,a[q]);
        
      }
      ans=max(ans,f);
    }
  }
  cout << ans << endl;
}  
