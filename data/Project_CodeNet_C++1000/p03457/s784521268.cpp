#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main(){
    ll N;
    cin >> N;
    bool check = true;
    vector<ll> t(N), x(N), y(N);
    for (int i = 0; i < N; i++) cin >> t[i] >> x[i] >> y[i];
    ll nx = 0;
    ll ny = 0;
    ll time = 0;
    for (int i = 0; i < N; i++) {
      time = t[i] - time;
      ll sum = abs(x[i] - nx) + abs(y[i] - ny);
      if(sum==0 && time%2==0)continue;
      else if(sum==0){
        check = false;
        break;
      }
      if (time%2 != sum%2) check = false;
      if (time < sum) check = false;
      nx = x[i];
      ny = y[i];
      time = t[i];
    }
    if(check) cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
}