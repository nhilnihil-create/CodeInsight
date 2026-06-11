//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;


int main(){
  string s;
  cin >> s;
  if(s == "A") printf("T\n");
  else if(s == "C") printf("G\n");
  else if(s == "G") printf("C\n");
  else if(s == "T") printf("A\n");
  return 0;
}
