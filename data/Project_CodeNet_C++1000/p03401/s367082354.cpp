#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
typedef long long ll;
typedef long double ld;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
  ll n,m,k,i,j,result=0;
  int a[200010]={0};
  string s;
  cin >> n;
  rep(i,n){
    cin >> a[i+1];
    result+=abs(a[i+1]-a[i]);
  }
  result+=abs(a[n]);
  for(i=1;i<=n;i++){
    m = result;
    m -= abs(a[i+1]-a[i])+abs(a[i]-a[i-1]);
    m += abs(a[i+1]-a[i-1]);
    cout << m << endl;
  }
  return 0;
}