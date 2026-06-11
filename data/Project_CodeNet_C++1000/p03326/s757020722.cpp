#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct beauty{
  ll x, y, z;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m;
  cin >> n >> m;
  vector < beauty > v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].x >> v[i].y >> v[i].z;
  }

  ll ans = 0;
  for(int p = -1; p <= 1; p++){
    for(int q = -1; q <= 1; q++){
      for(int r = -1; r <= 1; r++){
        if(p == 0 || q == 0 || r == 0) continue;
        vector < ll > pos_ans;
        for(int i = 0; i < n; i++){
          pos_ans.push_back(p * v[i].x + q * v[i].y + r * v[i].z);
        }
        sort(pos_ans.begin(), pos_ans.end(), greater < ll > ());
        ll sum = 0;
        for(int i = 0; i < m; i++){
          sum += pos_ans[i];
        }
        ans = max(ans, sum);
      }
    }
  }

  cout << ans << '\n';
}
