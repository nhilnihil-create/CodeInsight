#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int N;
  cin >> N;
  vector<ll> a(N), b(N);
  ll suma = 0, sumb = 0;
  REP(i, N) cin >> a[i], suma += a[i];
  REP(i, N) cin >> b[i], sumb += b[i];
  if (sumb < suma) {
    cout << "No" << endl;
    return 0;
  }
  queue<int> smalla{}, smallb{};
  REP(i, N) {
    if (a[i] == b[i]) {
      continue;
    }
    if (a[i] < b[i]) {
      smalla.push(i);
    } else {
      smallb.push(i);
    }
  }
  ll loopcnt = sumb - suma;
  REP(i, N) {
    if (a[i] < b[i]) {
      loopcnt -= (b[i] - a[i] + 1) / 2;
    }
  }
  if(loopcnt>=0){
      cout<<"Yes"<<endl;
  }else{
      cout<<"No"<<endl;
  }
}