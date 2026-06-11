#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll A, B;
vector<string> c;

int main() {
    cin >> A >> B;
    c.resize(100);
    for (int i = 0; i < 100; i++) {
        if (i >= 50) {
            c[i] = string(100, '#'); 
        } else {
            c[i] = string(100, '.'); 
        }
    }

    // 奇数行目について # を 1つおきに塗っていく
    int cnt = 0;
    for (int i = 0; i < 50; i += 2) {

        if (cnt >= B - 1) break;

        for (int j = 0; j < 100; j += 2) {
            if (cnt >= B - 1) break;
            c[i][j] = '#';
            cnt++;
        }
    }

    cnt = 0;

    for (int i = 51; i < 100; i += 2) {
        if (cnt >= A - 1) break;
        for (int j = 0; j < 100; j += 2) {
            if (cnt >= A - 1) break;
            c[i][j] = '.';
            cnt++;
        }
    }

    cout << 100 << " " << 100 << endl;
    for (int i = 0; i < 100; i++) {
        cout << c[i] << endl;
    }
}