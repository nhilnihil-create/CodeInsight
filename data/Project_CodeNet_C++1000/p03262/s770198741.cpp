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

ll cube (ll a){
  return a*a*a ;  
}
int main() {

ll n,x;
cin>>n>>x;
ll a[n];
REP(i,n){
  cin>>a[i];
}

vector<ll > vect;

REP(i,n){
  vect.push_back(abs(a[i]-x));
}

ll gcdd = vect[0];

REP(i,n){
  gcdd = gcd(gcdd,vect[i]);
}

cout<<gcdd<<"\n";



  
  return 0;
}
