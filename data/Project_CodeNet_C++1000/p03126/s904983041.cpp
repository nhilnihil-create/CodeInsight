#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int mod = 1000000007;
long long dp[100005];;

long long gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}

int main(){

 int n,m,x;
 int a[30] = {0};
 cin>>n>>m;

 for(int i=0;i<n;i++){
     cin>>x;
    for(int j=0;j<x;j++){
         int y;
       cin>>y;
       a[y-1]++;
    }
 }

  int cnt=0;
 for(int i=0;i<m;i++)
 {
    if(a[i] == n)
        cnt++;
 }

 cout<<cnt<<endl;

return 0;
}

