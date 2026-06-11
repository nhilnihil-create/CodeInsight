#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        --a;
        ans += a;
    }
    
    cout << ans << endl;
  return 0;
}