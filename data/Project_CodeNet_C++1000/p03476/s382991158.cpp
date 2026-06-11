#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool prime[100001];
int cnt[100001] = {0};

bool is_2017like(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
          prime[N] = false;
          return false;
        }
    }
    prime[N] = true;
    return prime[(N+1)/2];
}

void Main()
{
  ll q; cin >> q;
  prime[2] = true;
  prime[1] = false;
  for(int i = 4; i <= 100000; i++) {
    prime[i] = false;
    i++;
  }
  for(int i = 3; i <= 100000; i++) {
    if (is_2017like(i)) cnt[i] = cnt[i-1] + 1;
    else cnt[i] = cnt[i-1];
    i++;
    cnt[i] = cnt[i-1];
  }
  rep(i,q) {
    int l,r; cin >> l >> r;
    //cout << cnt[l-1] << ' ' << cnt[r] << endl;
    cout << cnt[r] - cnt[l-1] << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  Main();
  return 0;
}
