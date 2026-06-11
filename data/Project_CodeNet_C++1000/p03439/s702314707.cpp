#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int inout(int n){
  cout << n << endl;
  string res;
  cin >> res;
  if(res == "Male") return 1;
  if(res == "Female") return -1;
  return 0;
}

int main(){
  int n;
  cin >> n;
  int li = 0;
  int lv = inout(li);
  if(lv == 0) return 0;
  int ri = n-1;
  int rv = inout(ri);
  if(rv == 0) return 0;
  rep(i, 18){
    int mid = (li+ri)/2;
    int res = inout(mid);
    if(res == 0) break;
    int d = mid - li;
    if(((d % 2 == 1) ^ (res == lv)) == true){
      li = mid; lv = res;
    }else{
      ri = mid; rv = res;
    }
  }
  return 0;
}