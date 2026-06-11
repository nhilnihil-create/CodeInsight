#include <iostream>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){
  if(b == 0) return a;
  else return gcd(b , (a%b));
}

bool possible(ll a, ll b, string s, string t){
  ll gcdVal = gcd(a , b);
  ll pointerA = 0, pointerB = 0;
  ll addA = a / gcdVal, addB = b / gcdVal;

  bool flag = true;
  while((pointerA + addA) <= a && (pointerB + addB) <= b){
    if(s[pointerA] != t[pointerB]){
      flag = false;
      break;
    }
    pointerA += addA;
    pointerB += addB;
  }
  return flag;
}

void solve(ll a, ll b, string s, string t){
  if(possible(a , b , s , t) == true){
    cout << (a*b)/gcd(a,b) << endl;
  }
  else cout << - 1 << endl;
}

int main(){
  ll a, b;
  string s, t;
  cin >> a >> b;
  cin >> s >> t;

  solve(a , b, s , t);
}