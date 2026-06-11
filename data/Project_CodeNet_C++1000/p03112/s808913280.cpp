#include <bits/stdc++.h>
using namespace std;

int main() {

  long long INF = 1LL<<60;

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

    // 近い神社
    auto ns = lower_bound(s.begin(), s.end(), x[i]);
    // 左に近い神社 near_shrine_left
    long long nsl = *prev(ns);
    // 右に近い神社
    long long nsr = *ns;

    // 左に近い神社に近い寺
    auto nslt = lower_bound(t.begin(), t.end(), nsl);
    // 左に近い神社 -> 左に近い寺
    long long nsltl = *prev(nslt);
    // 左に近い神社 -> 右に近い寺
    long long nsltr = *nslt;

    if (0 < nsl && 0 < nsltl) {
      answer = abs(nsl - x[i]) + abs(nsltl - nsl);
    }

    if (0 < nsl && 0 < nsltr) {
      answer = min(answer, abs(nsl - x[i]) + abs(nsltr - nsl));
    }

    // 右に近い神社に近い寺
    auto nsrt = lower_bound(t.begin(), t.end(), nsr);
    // 右に近い神社 -> 左に近い寺
    long long nsrtl = *prev(nsrt);
    // 右に近い神社 -> 右に近い寺
    long long nsrtr = *nsrt;

    if (0 < nsr && 0 < nsrtl) {
      answer = min(answer, abs(nsr - x[i]) + abs(nsrtl - nsr));
    }

    if (0 < nsr && 0 < nsrtr) {
      answer = min(answer, abs(nsr - x[i]) + abs(nsrtr - nsr));
    }

    // 近い寺
    auto nt = lower_bound(t.begin(), t.end(), x[i]);
    // 左に近い寺 near_temple_left
    long long ntl = *prev(nt);
    // 右に近い寺
    long long ntr = *nt;

    // 左に近い寺に近い神社
    auto ntls = lower_bound(s.begin(), s.end(), ntl);
    // 左に近い寺 -> 左に近い神社
    long long ntlsl = *prev(ntls);
    // 左に近い寺 -> 右に近い神社
    long long ntlsr = *ntls;

    if (0 < ntl && 0 < ntlsl) {
      answer = min(answer, abs(ntl - x[i]) + abs(ntlsl - ntl));
    }

    if (0 < ntl && 0 < ntlsr) {
      answer = min(answer, abs(ntl - x[i]) + abs(ntlsr - ntl));
    }

    // 右に近い寺に近い神社
    auto ntrs = lower_bound(s.begin(), s.end(), ntr);
    // 右に近い寺 -> 左に近い神社
    long long ntrsl = *prev(ntrs);
    // 右に近い寺 -> 右に近い神社
    long long ntrsr = *ntrs;

    if (0 < ntr && 0 < ntrsl) {
      answer = min(answer, abs(ntr - x[i]) + abs(ntrsl - ntr));
    }

    if (0 < ntr && 0 < ntrsr) {
      answer = min(answer, abs(ntr - x[i]) + abs(ntrsr - ntr));
    }

    /*
    cout << x[i] << ":" << nsl << " " << nsltl << " -> " << abs(nsl - x[i]) + abs(nsltl - nsl) << endl;
    cout << x[i] << ":" << nsl << " " << nsltr << " -> " << abs(nsl - x[i]) + abs(nsltr - nsl) << endl;
    cout << x[i] << ":" << nsr << " " << nsrtl << " -> " << abs(nsr - x[i]) + abs(nsrtl - nsr) << endl;
    cout << x[i] << ":" << nsr << " " << nsrtr << " -> " << abs(nsr - x[i]) + abs(nsrtr - nsr) << endl;
    cout << x[i] << ":" << ntl << " " << ntlsl << " -> " << abs(ntl - x[i]) + abs(ntlsl - ntl) << endl;
    cout << x[i] << ":" << ntl << " " << ntlsr << " -> " << abs(ntl - x[i]) + abs(ntlsr - ntl) << endl;
    cout << x[i] << ":" << ntr << " " << ntrsl << " -> " << abs(ntr - x[i]) + abs(ntrsl - ntr) << endl;
    cout << x[i] << ":" << ntr << " " << ntrsr << " -> " << abs(ntr - x[i]) + abs(ntrsr - ntr) << endl;
    */
   
    cout << answer << endl;

  }

}