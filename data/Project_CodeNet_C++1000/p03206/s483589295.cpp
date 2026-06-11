#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main(){
  int D; cin>>D;
  string r = "Christmas";
  REP(i,25-D){ r += " Eve";}
  cout << r <<"\n";
}

