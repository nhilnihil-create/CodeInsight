#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

deque<pair<ll, ll>> q;
void pp(ll a, ll mid){
  if(a==1) q.push_front(make_pair(1, 1));
  else if(q.front().first<a) q.push_front(make_pair(a, 1));
  else if(q.front().first>a){
    while(q.front().first>a) q.pop_front();
    if(q.front().first==a) pp(a, mid);
    else pp(a, mid), pp(a, mid);
  }else {
    q.front().second++;
    while(q.front().first!=1&&q.front().second==mid+1){
      q.pop_front();
      if(q.front().first==a) pp(a-1, mid);
      else pp(a, mid), pp(a-1, mid);
    }
  }
}
int main(int argc, char const *argv[]) {
  ll N;
  std::cin >> N;
  std::vector<ll> A(N);
  ll now = 0;
  bool flag = true;
  for(int i=0;i<N;i++) {
    std::cin >> A[i];
    if(now<A[i]) now = A[i];
    else flag = false;
  }
  if(flag){
    std::cout << 1 << '\n';
    return 0;
  }
  ll l = 1, r = 1000000000;
  while(r-l>1){
    ll mid = (l+r)/2, one=0;
    if(A[0]!=1) pp(1, mid);
    for(int i=0;i<N;i++) pp(A[i], mid);
    //std::cout << "now" << mid << '\n';
    while(!q.empty()){
      //std::cout << q.front().first << " " << q.front().second << '\n';
      if(q.front().first==1) one+=q.front().second;
      q.pop_front();
    }
    if(one>mid||mid==1) l = mid;
    else r = mid;
  }
  std::cout << r << '\n';
  return 0;
}
