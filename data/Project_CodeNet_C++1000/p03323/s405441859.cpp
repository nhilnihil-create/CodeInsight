#include <iostream>
#include <algorithm>
#include <array>
#include <map>
#include <cmath>
#include <random>
#include <numeric>
#include <vector>
#include <string>
#include <set>

typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

using namespace std;
ll gcd(ll a, ll b){
  ll c;
  if(a<b){
    c=a;a=b;b=c;
  }
  while(b!=0){
    c=a%b;a=b;b=c;
  }
  return a;
}

ll lcm(ll a,ll b){
  ll c;
  c=a*b/gcd(a,b);
  return c;
}
int main() {
  int a,b;
  cin>>a>>b;
  if(a<9&&b<9)cout<<"Yay!";
  else cout<<":(";
}