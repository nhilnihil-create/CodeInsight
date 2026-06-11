#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main(){
  string s; cin >> s;
  vector<int> V(4);
  rep (i,4) V[i] = s[i] - '0';
  rep (bit, 1<<3){
    int sum = V[0];
    rep (i,3){
      if (bit & (1<<i)) sum += V[i+1];
      else sum -= V[i+1];
    }
    if (sum == 7){
      cout << V[0];
      rep (i,3){
        if (bit & (1<<i)) cout << "+" << V[i+1];
        else cout << "-" << V[i+1];
      }
      cout << "=7" << endl;
      return 0;
    }
  }
}