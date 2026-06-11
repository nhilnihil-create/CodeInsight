#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int D, N;
    cin >> D >> N;
    int ans = N * pow(100, D);
    if (N == 100)
    {
        ans += pow(100, D);
    }
    
    cout << ans << endl;

  return 0;
}