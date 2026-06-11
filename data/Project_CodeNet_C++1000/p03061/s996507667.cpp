#include <bits/stdc++.h>

/*............................*/

#define uint uint64_t
#define mx 100001
#define ll long long int
#define ull unsigned long long int
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define pi acos(-1)
#define eps 1e-8
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / __gcd(a, b)
#define input(ara, n)          \
   for (int i = 0; i < n; i++) \
   scanf("%d", &ara[i])
#define inputl(ara, n)                   \
   for (long long int i = 0; i < n; i++) \
   scanf("%lld", &ara[i])
#define pf(a) printf("%d\n", a);
#define pfl(a) printf("%lld\n", a);
#define pfi(a) printf("%d ", a);
#define pfll(a) printf("%lld ", a);
#define sc(a) scanf("%d", &a)
#define scc(a, b) scanf("%d %d", &a, &b)
#define sccdbl(a, b) scanf("%lf %lf", &a, &b)
#define sccc(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scccdbl(a, b, c) scanf("%lf %lf %lf", &a, &b, &c)
#define scl(a) scanf("%lld", &a)
#define sccl(a, b) scanf("%lld %lld", &a, &b)
#define scccl(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
using namespace std;
int main()
{
   // int t;
   // sc(t);
   // while (t--)
   // {

   // }
  int n;
  sc(n);
  ll ara[n];
  for(ll i=0;i<n;i++){
     scl(ara[i]);
  }
  ll preffix[n+2],suffix[n+2];
  preffix[1]=ara[0];
  for(ll i=2;i<=n;i++){
     preffix[i]=gcd(preffix[i-1],ara[i-1]);
  }
  suffix[n]=ara[n-1];
  for(ll i=n-1;i>=1;i--){
     suffix[i]=gcd(suffix[i+1],ara[i-1]);
  }
  ll ans=max(suffix[2],preffix[n-1]);
  for(ll i=2;i<n;i++){
     ans=max(ans,gcd(preffix[i-1],suffix[i+1]));
  }
  pfl(ans);
   return 0;
}
