#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)

int main()
{
  int ans = 0, n;
  int t=0, x=0, y=0;
  int t2, x2, y2;
  cin >> n;
  REP(i,0,n){
    cin >> t2 >> x2 >> y2;
    t = t2 - t;
    int sa = abs(x - x2) + abs(y -y2);
    if(sa<=t){
      int sa2 = abs(t- sa);
      if(sa2%2 == 1){
        ans=1;
      }else{
      }
    }else{
      ans = 1;
    }
    t = t2;
    x = x2;
    y = y2;
  }

  if(ans == 0)cout << "Yes" << endl;
  else cout << "No" << endl;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}