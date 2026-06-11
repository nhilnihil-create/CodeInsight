
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

 int gcd(int a,int b){

   if(a%b == 0)
    return b;
   else
    return gcd(b,a%b);

 }

 int main(){

  long long n,x;

  cin>>n>>x;

  long long a[n+1];

  for(int i=0;i<n;i++)
    cin>>a[i];

  a[n] = x;

  sort(a,a+n+1);

  int ans = a[1]-a[0];

  for(int i=0;i<n;i++){
     ans = gcd(ans,a[i+1]-a[i]);
  }

  cout<<ans<<endl;

 return 0;
 }
