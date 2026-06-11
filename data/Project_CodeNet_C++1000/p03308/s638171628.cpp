#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);


ll gcd(ll a, ll b){  if(b==0){  return a; }   return gcd(b , a%b); }

ll sum_digit(ll n){
  ll value = 0;

  while(n!=0){
    value += n%10;
    n = n/10;
  }

  return value;
}


int main() {


int n;
cin>>n;

ll a[n];
ll minn = INT_MAX, maxx = INT_MIN;
for(int i=0;i<n;i++){
  cin>>a[i];

  minn = min(a[i],minn);
  maxx = max(a[i],maxx); 
}

cout<<abs(minn-maxx)<<"\n";



  
  return 0;
}
