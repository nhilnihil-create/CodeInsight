#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;

  string S;
  cin >> S;

  int Q;
  cin >> Q;

  for(int q = 0; q < Q; q++){
    int k;
    cin >> k;

    long long ans = 0;
    long long d_cnt = 0, dm_cnt = 0, m_cnt = 0;
    for(int i = 0; i < S.length(); i++){
      if(i - k >= 0 && S[i - k] == 'D'){
        d_cnt--;
        dm_cnt -= m_cnt;
      }
      if(i - k >= 0 && S[i - k] == 'M'){
        m_cnt--;
      }
      if(S[i] == 'D'){
        d_cnt++;
      }
      if(S[i] == 'M'){
        dm_cnt += d_cnt;
        m_cnt++;
      }
      if(S[i] == 'C'){
        ans += max(0LL, dm_cnt);
      }
    }

    cout << ans << endl;
  }
}
