#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> t(N), v(N), s(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
        t[i] <<= 1;
        s[i + 1] = t[i] + s[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        v[i] <<= 1;
    }
    int time = s[N];
    vector<int> mx(time);   //各時間に出せる最大速度
    for (int i = 0; i < time / 2; i++) {
        mx[i] = i;
    }
    for (int i = time / 2; i < time; i++) {
        mx[i] = time - i;
    }
    int ans = 0;
    for (int j = 0; j < time; j++) {
        for (int i = 0; i < N; i++) {
            if (j < s[i]) {
                mx[j] = min(mx[j], -(j - s[i]) + v[i]);
            } else if (j > s[i + 1]) {
                mx[j] = min(mx[j], j - s[i + 1] + v[i]);
            } else {
              mx[j] = min(mx[j], v[i]);
            }
        }
        ans += mx[j];
    }
    cout << fixed << setprecision(4) << (double) ans * 0.25 << endl;
}



