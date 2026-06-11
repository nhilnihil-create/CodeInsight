#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  cout << 0 << endl;
  string res;
  bool frg;
  cin >> res;
  if(res == "Vacant") return 0;
  else if(res == "Male") frg = true;
  else frg = false;
  cout << n-1 << endl;
  cin >> res;
  if(res == "Vacant") return 0;
  // else if(res == "Female") reg = false;
  // else reg = true;
  int l = 0, r = n-1;
  int co = 1;
  while(co < 20){
    co++;
    // cerr << l << " " << r << endl;
    int mid = (l+r)/2;
    bool mig;
    cout << mid << endl;
    cin >> res;
    if(res == "Vacant") return 0;
    else if(res == "Male") mig = true;
    else mig = false;
    int lw = mid - l;
    bool m2 = (lw % 2 == 0);
    bool ge = (frg == mig);
    if((m2 ^ ge) == true){
      r = mid;
    }else{
      frg = mig;
      l = mid;
    }
  }

  return 1;
}