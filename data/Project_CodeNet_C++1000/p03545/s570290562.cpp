#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;

int main(){
  string s; cin>>s;
  vector<int>v(4);
  for(int i=0; i<4; i++) v[i] = s[i] - '0';

  rep(bit, 1<<3){
    int sum = v[0];
    rep (i,3){
      if (bit & (1<<i)) sum += v[i+1];
      else sum -= v[i+1];
    }
    if (sum==7){
      rep(i,4){
        cout << v[i];
        if (i!=3){
          if (bit & (1<<i)) cout << "+";
          else cout << "-";
        }
      }
      cout << "=7" << endl;
      return 0;
    }
  }
}