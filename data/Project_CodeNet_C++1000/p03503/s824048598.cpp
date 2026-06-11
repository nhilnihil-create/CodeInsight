#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int test[12345678], aa[1234][1234], bb[1234][1234];
signed main() {
	int n, a, b, cnt = 1, ans = -100000000000;
	cin >> n;
    for (int h = 0; h < n; h++) {
        for (int i = 0; i < 10; i++) { cin >> aa[h][i]; }
    }
    for (int h = 0; h < n; h++) {
        for (int i = 0; i <= 10; i++) { cin >> bb[h][i]; }
    }
    for (int i = 0; i <= (1 << 10); i++) {
        vector<int> sep = { };
        for (int j = 0; j <= 9; j++) {
            if ((i & (1 << j)) > 0) {
                sep.push_back(j);
            }
        }
        if (sep.size() == 0) { continue; }
        int sum = 0;
        for (int h = 0; h < n; h++) {
            cnt = 0;
            for (int j = 0; j < sep.size(); j++) {
                if (aa[h][sep[j]] == 1) { cnt++; }
            }
            sum += bb[h][cnt];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
	return 0;
}