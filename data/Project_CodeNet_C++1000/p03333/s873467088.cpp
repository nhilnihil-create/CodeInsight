#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)

int N;

vector<i64> L,R;

int main(){
    cin >> N;
    L.resize(N);
    R.resize(N);
    rep(i,0,N - 1) cin >> L[i] >> R[i];

    using P = pair<i64,i64>;
    vector<i64> LL,RR;
    rep(i,0,N - 1){
      LL.push_back(L[i] * 2);
      RR.push_back(-R[i] * 2);
    }

    sort(LL.rbegin(),LL.rend());
    sort(RR.rbegin(),RR.rend());
    i64 ans = 0;

    {
      i64 sum = 0;
      for(int i = 0;i < N;i++){
        sum += LL[i];
        ans = max(ans , sum);
        sum += RR[i];
        ans = max(ans , sum);
      }
    }
    {
      i64 sum = 0;
      for(int i = 0;i < N;i++){
        sum += RR[i];
        ans = max(ans , sum);
        sum += LL[i];
        ans = max(ans , sum);
      }
    }

    cout << ans << endl;
}

