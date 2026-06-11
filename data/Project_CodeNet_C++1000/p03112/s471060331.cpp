#include <bits/stdc++.h>
using namespace std;

long long INF = 1LL<<60;


long long calc(vector<long long>& s, vector<long long>& t, long long x) {

  long long answer = INF;
  
  auto a_ = lower_bound(s.begin(), s.end(), x);
  
  for (int i = 0; i < 2; i++) {
    
    long long ax_ = *prev(a_);

    if (i == 1) {
      ax_ = *a_;
    }

    auto b_ = lower_bound(t.begin(), t.end(), ax_);

    long long bxl_ = *prev(b_);
    long long bxr_ = *b_;

    if (0 < ax_ && 0 < bxl_) {
      answer = min(answer, abs(ax_ - x) + abs(bxl_ - ax_));
    }

    if (0 < ax_ && 0 < bxr_) {
      answer = min(answer, abs(ax_ - x) + abs(bxr_ - ax_));
    }

  }

  return answer;

}


int main() {

  int A, B, Q;
  cin >> A >> B >> Q;

  vector<long long> s;
  s.push_back(0);
  for (int i = 1; i <= A; i++) {
    long long s_;
    cin >> s_;
    s.push_back(s_);
  }
  s.push_back(INF);

  vector<long long> t(B+2);
  t.push_back(0);
  for (int i = 1; i <= B; i++) {
    long long t_;
    cin >> t_;
    t.push_back(t_);
  }
  t.push_back(INF);

  vector<long long> x(Q);
  for (int i = 0; i < Q; i++) {
    cin >> x[i];
  }

  for (int i = 0; i < Q; i++) {

    long long answer = INF;

    answer = min(calc(s,t,x[i]), calc(t,s,x[i]));

    cout << answer << endl;

  }

}