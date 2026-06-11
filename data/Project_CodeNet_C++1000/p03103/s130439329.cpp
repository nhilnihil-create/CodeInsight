#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;
using ping = pair<ll, ll>;

int main(){
    ll N, M;
    cin >> N>>M;
    vector<ping> S(N);
    for (int i = 0; i < N; i++) cin >> S[i].first >> S[i].second;
    sort(S.begin(), S.end());

    ll price = 0, num = 0;
    for (int i = 0; i<N; i++){
      for (int j = 1; j <= S[i].second; j++){
        num++;
        if(num==M || j==S[i].second){
          price += S[i].first * j;
          break;
        }
      }
      if (num == M) break;
    }
    cout << price << endl;
    return 0;
}