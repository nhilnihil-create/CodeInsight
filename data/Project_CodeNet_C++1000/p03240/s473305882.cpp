#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<int> x(N), y(N), h(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i] >> h[i];

    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int H = -1;
            bool can = true;
            for (int i = 1; i < N; i++) {
                if (h[i] == 0) continue;
                int tmp = h[i] + abs(cx - x[i]) + abs(cy - y[i]);
                if (H == -1) H = tmp;
                if (H != tmp) can = false;
            }
            if (!can) continue;
            for (int i = 0; i < N; i++) {
                int Hi = max(H - abs(cx - x[i]) - abs(cy - y[i]), 0);
                if (Hi != h[i]) can = false;
            }
            if (can) {
                cout << cx << ' ' << cy << ' ' << H << '\n';
                return 0;
            }
        }
    }
}
