#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define fo(i,b,n) for(int i=b;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sll(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define endl "\n"
#define PI 3.1415926535897932384626
const int mod = 1000000007;
/*===========================================================================*/


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  float n, k; cin>>n>>k;
  float ans = ceil((n-1)/(k-1));


  cout<<ans;



  return 0;
}
