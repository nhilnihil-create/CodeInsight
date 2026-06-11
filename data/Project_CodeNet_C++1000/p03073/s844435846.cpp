#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string S;
    cin >> S;
    ll N = S.size();
    ll cnt = 0;
    for (int i = 1; i < N; i++) {
      if (S[i] == S[i - 1]) {
          if(S[i]=='0'){
            S[i] = '1';
            cnt++;
          }
          else if(S[i]=='1'){
              S[i] = '0';
              cnt++;
          }
      }
    }
    cout << cnt << endl;
    return 0;
}