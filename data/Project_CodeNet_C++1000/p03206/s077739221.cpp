#include <bits/stdc++.h>
#define INF 2e9
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}

int main(){
  int D;
  cin >> D;
  if(D==25) cout << "Christmas" << endl;
  if(D==24) cout << "Christmas Eve" << endl;
  if(D==23) cout << "Christmas Eve Eve" << endl;
  if(D==22) cout << "Christmas Eve Eve Eve" << endl;
}