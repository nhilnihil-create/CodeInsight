#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
  int n,a,b; cin >> n >> a >> b;
  vi level(3,0);
  int p;
  rep(i,n){
    cin >> p;
    if(p>b)level[2]++;
    else if(p>a)level[1]++;
    else level[0]++;
  }
  
  cout << min(level[0], min(level[1], level[2])) << endl;
  return 0;
}