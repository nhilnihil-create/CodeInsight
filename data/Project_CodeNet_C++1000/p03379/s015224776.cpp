#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 100100100;

 
int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  vector<int> c = x;
  sort(c.begin(),c.end());

  int id = n/2-1;

  rep(i,n){
    if(x[i]<=c[id]) cout << c[id+1] << endl;
    else cout << c[id] << endl;
  }
  
}
