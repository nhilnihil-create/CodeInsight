/* BISMILLAHIR RAHMANIR RAHIM */
#include<bits/stdc++.h>
using namespace std;
#define ll       long long
#define ull       unsigned long long
#define  si(x)   scanf("%d", &x)
#define  sll(x)   scanf("%lld", &x)
#define  sd(x)   scanf("%lf", &x)
#define l0(i,n)   for(ll i=0; i<n; i++)
#define MAX       100000
#define maxn 	  200002
#define pb 		  push_back
#define mk 		  make_pair
#define endl	  "\n"
#define INF 	  1000000000
#define MOD		  1000000007

int ans=0;
void dfs(ll n,ll m){
  if(n>m) return;
  vector<int> c(10);
  ll x=n;
  while(x>0){
    c[x%10]++;
    x/=10;
  }
  if(c[3]>0 && c[5]>0 && c[7]>0) ans++;
  dfs(n*10+3,m);
  dfs(n*10+5,m);
  dfs(n*10+7,m);
  return;
}

int main ()
{
		ios::sync_with_stdio(0);
		cin.tie(0);
		//CODE TONOY
	    ll m,n=0;
	    sll(m);
	    dfs(n,m);
	    cout << ans << endl;
		return 0;
}
