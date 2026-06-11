#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 3e4 + 1;
int a[N];
int m = 0;
vector<int> v[3];
bool used[N], good[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 3) {
        cout << "2 5 63" << "\n";
        return 0;
    }


    for (int i = 4; i <= 30000 && n > 0; i++) {
        if (i % 2 == 0 || i % 3 == 0) {
            v[i % 3].push_back(i);
            good[i] = true;
        }
    }

    used[2] = used[3] = true;
    n -= 2;

    for (int i = 0; i <= v[1].size(); i++) {
        bool ok = false;
        for (int j = 0; j <= v[2].size(); j++) {
            if ((i + j + j) % 3 == 1 && i + j < n &&
                (i + j + v[0].size()) >= n) {

                for (int k = 0; k < i; k++) {
                    used[v[1][k]] = true;
                    n--;
                }
                for (int k = 0; k < j; k++) {
                    used[v[2][k]] = true;
                    n--;
                }
                for (int k = 0; n > 0; k++) {
                    used[v[0][k]] = true;
                    n--;
                }
                ok = true;
                break;
            }
        }
        if (ok)
            break;
    }

    int s = 0;

    for (int i = 0; i < N; i++) {
        if (used[i]) {
            s += i;
        }
    }

    if (s % 2) {
        for (int j = 4; j < N; j++) {
            if (used[j]) {
                for (int k = 4; k < N; k++) {
                    if (!used[k] && good[k]) {
                        if (((k ^ j) & 1) && (j - k) % 3 == 0) {
                            used[j] = false;
                            used[k] = true;
                            break;
                        }
                    }
                }
                if (!used[j])
                    break;
            }
        }
    }

    for (int i = 1; i < N; i++) {
        if (used[i])
            cout << i << " ";
    }

    return 0;
}