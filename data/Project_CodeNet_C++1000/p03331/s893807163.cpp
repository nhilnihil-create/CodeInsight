#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
 
 
 
int main(){
  int n;
  cin >> n;
  int minc = 2000000000;
  REP2(i,1,n){
    int a = i;
    int b = n - a;
    int cnt_a = 0;
    int cnt_b = 0;
    for(int j = 5; j >= 0; --j){
      int x = 1;
      REP(k,j) x *= 10;
      cnt_a += a/x;
      a %= x;
      cnt_b += b/x;
      b %= x;
    }
 
    //cout << cnt_a<<" " << cnt_b << endl;
 
    minc = min(minc, cnt_a + cnt_b);
  }
 
  cout << minc << endl;
  return 0;
}