#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  string s; cin >>s;
  int a=count(s.begin(),s.end(),'R');
  int b=N-a;
  cout <<(a>b ? "Yes":"No") <<endl;
  return 0;
}
