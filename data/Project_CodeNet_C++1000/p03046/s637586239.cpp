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
#include <iomanip>
#define vll vector<ll>
#define vvv vector<vvl>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvvl(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define rep(c, a, b) for(ll c=a;c<b;c++)
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

vll s(60, 1);
void init(){rep(i, 1, 60) s[i] = s[i-1] * 2;}
int main(int argc, char const *argv[]) {
  ll m, k;std::cin >> m >> k;
  init();
  if(k>=s[m]){
    std::cout << -1 << '\n';
    return 0;
  }
  if(m==1){
    std::cout << (k==0?"0 0 1 1":"-1") << '\n';
    return 0;
  }
  if(k==0){
    re(i, s[m]){
      std::cout << i << " ";
      std::cout << i << (i==s[m]-1?"\n":" ");
    }
    return 0;
  }
  set<ll> B;
  re(i, s[m]) if(i!=k) B.insert(i);
  vll A;
  if(k==1) A = vll{2, 3};
  else A = vll{1, k^1};
  B.erase(A[0]);B.erase(A[1]);
  vll ans;
  ans.push_back(k);
  for(auto itr = B.begin();itr!=B.end();itr++) ans.push_back((*itr));
  ans.push_back(A[0]), ans.push_back(A[1]);
  for(auto itr = B.end();B.size()!=0;){
    itr--;
    ans.push_back((*itr));
    if(itr==B.begin()) break;
  }
  ans.push_back(k);
  ans.push_back(A[1]), ans.push_back(A[0]);
  re(i, ans.size()) std::cout << ans[i] << (i==ans.size()-1?"\n":" ");
  return 0;
}
