#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Z, W;
    cin >> N >> Z >> W;

    vector<int> a(N);

    vector<int> x(N, 1000000005);
    vector<int> y(N);

    for(int i = 0; i < N; i++) cin >> a[i];

    for(int i = N - 2; i >= 0; i--) {
        for(int j = i + 1; j < N - 1; j++) {
            x[i] = min(x[i], y[j]);
        }
        x[i] = min(x[i], abs(a[i] - a[N - 1]));

        for(int j = i + 1; j < N - 1; j++) {
            y[i] = max(y[i], x[j]);
        }
        y[i] = max(y[i], abs(a[i] - a[N - 1]));
    }

    x[N - 1] = abs(a[N - 1] - W);

    cout << *max_element(x.begin(), x.end()) << endl;
}