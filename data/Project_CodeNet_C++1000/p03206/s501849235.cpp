#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int d;
  cin >> d;
  if(d==25){cout << "Christmas" << endl;}
  if(d==24){cout << "Christmas Eve" << endl;}
  if(d==23){cout << "Christmas Eve Eve" << endl;}
  if(d==22){cout << "Christmas Eve Eve Eve" << endl;}
}