# include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

long long n, x[N], v[N], pref[N], suff[N], a[N], b[N], c[N], d[N], C;
long long ans;

int main(){
      cin >> n >> C;

      for(int i = 1; i <= n; i ++){
            cin >> x[i] >> v[i];
            pref[i] = pref[i - 1] + v[i];
            c[i] = max(c[i - 1], pref[i] - x[i] - x[i]);
      }

      for(int i = n; i >= 1; i --){
            suff[i] = suff[i + 1] + v[i];
            a[i] = pref[i] - x[i];
            b[i] = suff[i] - (C - x[i]);
            d[i] = max(d[i + 1], suff[i] - (C - x[i]) - (C - x[i]));
            ans = max(ans, a[i] + d[i + 1]);
            ans = max(ans, b[i] + c[i - 1]);
            ans = max(ans, max(a[i], b[i]));
      }

      cout << ans << endl;
}
