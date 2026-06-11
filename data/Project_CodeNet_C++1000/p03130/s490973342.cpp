#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  vector<int> city(4);
  rep(i,0,3) {
    int a,b; cin >>a >>b;
    city[a-1]++;
    city[b-1]++;
  }
  if (city[0]==1 && city[1]==2 && city[2]==2 && city[3]==1) {
    cout <<"YES" <<endl;
  } else {
    cout <<"NO" <<endl;
  }
  return 0;
}
