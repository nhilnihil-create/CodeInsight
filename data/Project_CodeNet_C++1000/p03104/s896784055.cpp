#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll f(ll n){
  if(n<=0)return 0;
  ll num1=n/2;
  ll num2=n%2;
  if(num2==0){
    return (num1%2)^n;
  } else {
    return (num1+1)%2;
  }
}

int main(){
  ll a, b;
  cin >> a >> b;
  ll ans=f(a-1)^f(b);
  cout << ans << endl;
  return 0;
}
