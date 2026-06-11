#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main(){
    ll N;
    string S;
    cin >> N;
    cin >> S;
    ll left = 0, right = 0;
    for (int i = 0; i < N; i++){
      if (S[i] == 'W') left++;
      else
        right++;
    }

    ll tmpl = 0, tmpr = 0;
    ll cnt = INF;
    for (int i = 0; i < N; i++) {
      if (S[i] == 'W')
        tmpl++;
      else
        tmpr++;
      if(S[i]=='W'){
        cnt = min(cnt, right - tmpr + tmpl - 1);
      }
      else{
        cnt = min(cnt, tmpl + right - tmpr);
      }
    }
    cout << cnt << endl;
    return 0;
}