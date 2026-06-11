#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> v(n);
    int a, b, c;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        c = a+b;
        v[i] = c;
        ans -= b;
    }
    /*
      for(vector<int> tmp : v) {
          cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << endl;
      }
      */
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < n; i += 2) {
        ans += v[i];
    }
    cout << ans << endl;
    return 0;
}
