#include <iostream>
#include <cmath>
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
typedef long long int ll;
const ll INF = 100100100100100100;

ll N;
ll A[200200];
ll rui[200200];
ll ans = INF;

void init_rui() {
  rep(i,N) {
    rui[i+1] = A[i] + rui[i];
  }
}

ll get_rui(ll left, ll right) {
  return rui[right + 1] - rui[left];
}

int main() {
  cin >> N;
  rep(i,N) {
    cin >> A[i];
  }
  init_rui();
  
  ll left_center = 0;
  ll right_center = 0;
  
  
  rep(i,N + 1) {
    if (i < 2 || i >= N - 1) continue;
    //cerr << "itr " << i << endl;
    
    ll left_max  = -INF;
    ll left_min  = INF;
    ll right_max = -INF;
    ll right_min = INF;
    
    ll left_diffmin = INF;
    ll right_diffmin = INF;
    while(1) {
      while (left_center < 1) left_center++;
      if (left_center > i-1) {
        left_center--;
        break;
      }
      //cerr << "in left_center: " << left_center << endl;
      ll ll_sum = get_rui(0, left_center-1);
      ll lr_sum = get_rui(left_center, i-1);
      //cerr << "ll_sum : " << ll_sum << " , lr_sum : " << lr_sum << endl;
      if (abs(ll_sum - lr_sum) < left_diffmin) {
        left_max = max(ll_sum, lr_sum);
        left_min = min(ll_sum, lr_sum);
        left_diffmin = abs(ll_sum - lr_sum);
      }
      if (ll_sum >= lr_sum) {
        left_center--;
        break;
      }
      left_center++;
    }
    
    while(1) {
      while (right_center < i+1) right_center++;
      if (right_center > N-1) {
        right_center--;
        break;
      }
      //cerr << "in right_center: " << right_center << endl;
      ll rl_sum = get_rui(i, right_center-1);
      ll rr_sum = get_rui(right_center, N-1);
      //cerr << "rl_sum : " << rl_sum << " , rr_sum : " << rr_sum << endl;
      if (abs(rl_sum - rr_sum) < right_diffmin) {
        right_max = max(rl_sum, rr_sum);
        right_min = min(rl_sum, rr_sum);
        right_diffmin = abs(rl_sum - rr_sum);
      }
      if (rl_sum >= rr_sum) {
        right_center--;
        break;
      }
      right_center++;
    }
    //cerr << "left_max : " << left_max << " right_max : " << right_max << endl;
    //cerr << "left_min : " << left_min << " right_min : " << right_min << endl;
    ans = min(ans, max(left_max, right_max) - min(left_min, right_min));
    //cerr << "ans: " << ans << endl;
  }
  cout << ans << endl;
}