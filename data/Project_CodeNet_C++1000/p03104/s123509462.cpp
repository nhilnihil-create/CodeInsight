#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
 
#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX_N 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2);

/*
	<<XORの性質>>
    n^n=0 ・・・自明
    n^(n+1)=1　・・・ビット差１なので
    F(A,B)=F(0,A-1)^F(0,B)より
    F(0,n)のみ求めれば良い
    
    F(0,6)=0^1^2^3^4^5^6
    =(0^1)^(2^3)^(4^5)^6
    =1^1^1^6
*/

ll f(ll n)
{
  ll ret;
  if (n%2==0) ret = n;
  else ret = 0;
  
  ll num = (n+1)/2;
  if (num%2==0) ret = ret^0;
  else ret = ret^1;
  return (ret);
}

int main()
{
  ll A,B;cin>>A>>B;
  ll a = f(A-1);
  ll b = f(B);
  ll ans = a^b;
  cout<<ans<<endl;
}