#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;
using ping = pair<ll, ll>;

int main(){
    string S;
    cin >> S;

    ll cnt_0 = 0, cnt_1 = 0;
    for (int i = 0; i < S.size(); i++) {
      if (S[i] == '0') cnt_0++;
      else
        cnt_1++;
    }
    cout << 2*min(cnt_0, cnt_1) << endl;
    return 0;
}