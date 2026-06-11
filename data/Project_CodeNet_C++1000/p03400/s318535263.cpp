#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  int n,d,x; cin >> n >> d >> x;

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    for(int j = 1; j <= d; j++){
      int temp = j * a + 1;
      if(temp <= d) x++;
    }
  }
  cout << x+n << endl;
  return 0;
}
