#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

// DMC
int main() {
  int N, Q;
  string str;
  cin >> N >> str >> Q;
  
  for (int q = 0; q < Q; q++) {
    int k;
    cin >> k;
    
    ll cnt = 0;
    ll d_cnt = 0;
    ll m_cnt = 0;
    ll dm_cnt = 0;
    for (int i = 0; i < N; i++) {
      if (str[i] == 'D') {
        d_cnt++;
      } else if (str[i] == 'M') {
        m_cnt++;
        dm_cnt += d_cnt;
      } else if (str[i] == 'C') {
        cnt += dm_cnt;
      }
      
      if (i >= k - 1) {
        if (str[i - k + 1] == 'D') {
          dm_cnt -= m_cnt;
          d_cnt--;
        } else if (str[i - k + 1] == 'M') {
          m_cnt--;
        }
      }
    }
    
    cout << cnt << endl;
  }
  return 0;
}