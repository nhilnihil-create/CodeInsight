#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    int N; cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X.at(i);
        Y.at(i) = X.at(i);
    }
    sort(Y.begin(), Y.end());
    int left = Y.at(N / 2 - 1), right = Y.at(N / 2);
    for (int i = 0; i < N; i++) {
        if (X.at(i) <= left) {
            cout << right << endl;
        }
        else {
            cout << left << endl;
        }
    }
    return 0;
}