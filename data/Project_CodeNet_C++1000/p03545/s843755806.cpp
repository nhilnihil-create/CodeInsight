#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using vi=vector<int>;
using vvi=vector<vi>;
using ll=long long;

int main() {
  string ABCD; cin >>ABCD;
  vi abcd(4);
  rep(i,0,4) {
    abcd[i]=ABCD[i]-'0';
  }

  int all=1<<3;

  rep (bit,0,all) {
    int sum=abcd[0];
    string formula="";
    formula+=ABCD[0];
    rep(i,0,3) {
      if (bit>>i&1) {
        sum+=abcd[i+1];
        formula+='+';
      } else {
        sum-=abcd[i+1];
        formula+='-';
      }
      formula+=ABCD[i+1];
    }
    if (sum==7) {
      cout <<formula <<"=7" <<endl;
      return 0;
    }
  }
}
