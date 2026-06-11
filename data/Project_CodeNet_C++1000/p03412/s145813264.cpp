#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  int n, b;std::cin >> n;
  int MAX = 30;
  vector<int> a(n),s(MAX+1, 1);
  vvi amari = vv(MAX, n, 0, int);
  for(int i=1;i<MAX+1;i++) s[i] = s[i-1] * 2;
  for(int i=0;i<n;i++) scanf("%d", &a[i]);
  for(int i=0;i<n;i++){
    scanf("%d", &b);
    for(int j=0;j<MAX;j++) amari[j][i] = (b%s[j+1]);
  }
  for(int i=0;i<MAX;i++) sort(amari[i].begin(), amari[i].end());
  vector<ll> xo(MAX, 0);
  for(int i=0;i<n;i++){
    int t = 0;
    for(int j=0;j<MAX;j++){
      t += s[j] * ((a[i]&(1<<j))!=0?1:0);
      if((a[i]&(1<<j))==0){
        ll out = (1<<(j+1)) - t;
        ll ok = max(0, (1<<j)-t);
        ll r = lower_bound(amari[j].begin(), amari[j].end(), out) - amari[j].begin();
        ll l = lower_bound(amari[j].begin(), amari[j].end(), ok) - amari[j].begin();
        xo[j] += r - l;
      }else{
        int out_1 = (1<<(j+1)) - t;
        int ok_1  = 0;
        int out_2 = 4*(1<<j) - t;
        int ok_2 = 3*(1<<j) - t;
        int r = lower_bound(amari[j].begin(), amari[j].end(), out_1) - amari[j].begin();
        int l = lower_bound(amari[j].begin(), amari[j].end(), ok_1) - amari[j].begin();
        int r2 = lower_bound(amari[j].begin(), amari[j].end(), out_2) - amari[j].begin();
        int l2 = lower_bound(amari[j].begin(), amari[j].end(), ok_2) - amari[j].begin();
        xo[j] += r - l + r2 - l2;
      }
    }
  }
  ll ans = 0;
  for(int i=0;i<MAX;i++) ans += s[i] * (xo[i]%2);
  std::cout << ans << '\n';
  return 0;
}
