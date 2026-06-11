#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(i, m) cin >> b[i];
  int cnt = 0;
  rep(i, n){
    int sum = 0;
    rep(j, m){
      int num;
      cin >> num;
      sum += num*b[j];
    }
    sum += c;
    if(sum>0) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
