#include <iostream>
#include <cstring>
#include <map>
#define ll long long
using namespace std;

ll gcd (ll a, ll b){
  if (b==0)
    return a;
  return gcd(b, a%b);
}


char arr[100005];
int main() {
  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  //f = gcd, g = lcm
  int f = gcd(n, m);
  ll g = (n*m)/f;

  int cntr = 1;
  for (int i = 0; i < s.length(); i+=n/f){
    char d = s[i];
    arr[cntr] = d;
    cntr++;
  }

  ll w = 1;
  for (int i = 0; i < t.length(); i+=m/f, w++){
   if (t[i] != arr[w]){
     cout << "-1" << endl;
     return 0;
   }
  }

  cout << g << endl;
  return 0;
}