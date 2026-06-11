#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;

    int x = 1900 * M + 100 * (N - M);
    cout << pow(2, M) * x << endl;
}