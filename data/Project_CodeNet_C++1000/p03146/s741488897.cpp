#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int s;
  cin >> s;
  vi v(1000000);
  v[0] = s;
  rep(i,1000000){
    if(v[i]%2 == 0) v[i+1] = v[i]/2;
    else v[i+1] = 3*v[i] + 1;
  }
  rep(i,1000000)rep(j,1000000){
    if(i==j) continue;
    if(v[i] == v[j]){
      cout << j+1 << endl;
      return 0;
    }
  }
}
