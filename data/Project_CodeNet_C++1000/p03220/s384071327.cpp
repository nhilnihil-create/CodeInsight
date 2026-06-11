#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int   N, T, A;
    float H;
    int   ansN = 0;
    float ansD = INF;
    cin >> N >> T >> A;
    for (int i = 0; i < N; i++) {
        cin >> H;
        H = abs(A - (T - H * 0.006));
        if (ansD > H) {
            ansD = H;
            ansN = i;
        }
    }
    cout << ansN + 1 << endl;
}
