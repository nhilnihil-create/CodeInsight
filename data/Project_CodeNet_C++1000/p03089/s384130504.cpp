#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int>b(N);
    vector<int>check(N, true);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    int cnt = 0;
    vector<int>a;
    int c = N;
    while (c--) {
        int loc = N-cnt;
        int i;
        for (i = N-1; i >= 0; i--) {
            if (check[i] == true && loc == b[i]) {
                check[i] = false;
                a.push_back(b[i]);
                cnt++;
                break;
            } else {
                if (check[i] == false) {
                    continue;
                }
                loc--;
            }
        }
        if (i==-1) {
            break;
        }
    }
    if (a.size() != N) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < N; i++) {
            cout << a[N-1-i] << endl;
        }
    }
}
