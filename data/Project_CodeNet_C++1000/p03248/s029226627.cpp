#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define ALL(x) x.begin(),x.end()
#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

typedef long long ll;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }


void compute() {

}

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if( s[0] != '1' || s[n-1] != '0' ) { puts("-1"); return 0; }
  int croot = 1;
  int idx = 3;
  typedef pair<int,int> ii;
  vector<ii> vec;
  vec.push_back(ii(1,2));
  REP(i,1,n-1) {
    if( s[i] == '0' ) {
      vec.push_back(ii(croot,idx++));
    } else {
      vec.push_back(ii(croot,idx));
      int rem = n - idx + 1;
      if( s[rem-1] == '0' ) { puts("-1"); return 0; }
      croot = idx++;
    }
  }
  rep(i,(int)vec.size()) {
    cout << vec[i].first << " " << vec[i].second << endl;
  }
  compute();
  return 0;
}
