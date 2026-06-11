#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;

int main() {
  int x; cin >> x;
  vector<bool> expo(x+1);
  expo[1] = 1;
  for(int b=2;b<=x;b++){
    int v = b*b;
    while(v<=x){
      expo[v]=1;
      v*=b;
    }
  }
  for(int i=x;i>=1;i--)if(expo[i]){
    cout << i << endl;
    return 0;
  }
 
}