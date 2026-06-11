#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A, B;
    cin >> N >> A >> B;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        string stri = to_string(i);
        int ketasum = 0;
        rep(j, stri.size()) { ketasum += stri[j] - '0'; }

        if (ketasum >= A && ketasum <= B)
            sum += i;
    }

    cout << sum << endl;
}