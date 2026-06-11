#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int n, q;
  string s;
  vector<int> kq;
  cin >> n;
  cin >> s;
  cin >> q;
  kq.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> kq[i];
  }
  
  for (int i = 0; i < q; i++) {
    ll cnt = 0;
    ll cnt_d = 0;
    ll cnt_m = 0;
    ll cnt_dm = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == 'D') {
        cnt_d++;
      } else if (s[j] == 'M') {
        cnt_m++;
        cnt_dm += cnt_d;
      } else if (s[j] == 'C') {
        cnt += cnt_dm; 
      }
      if (j >= kq[i] - 1) {
        if (s[j - kq[i] + 1] == 'D') {
          cnt_dm = cnt_dm - cnt_m;
          cnt_d--;
        } else if (s[j - kq[i] + 1] == 'M') {
          cnt_m--; 
        }
      }
    }
    cout << cnt << endl;
  }
  
 	return 0; 
}
