#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

bool check(int i, int t ,vector<vector<int> > &s) {
    for (int j = 0; j < 20; j++) {
        if (s[t+1][j] - s[i][j] > 1)
            return false;
    }
    return true;
}

int main() {
    int n;  cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int> > b(n, vector<int>(20, 0)), s(n+1, vector<int>(20, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 20; j++) {
            b[i][j] = a[i] % 2;
            a[i] /= 2;
            s[i+1][j] = s[i][j] + b[i][j];
        }
    }
    
    long long ans = 0, t = 0;
    for (int i = 0; i < n; i++) {
        while (t+1 < n && check(i, t+1, s))
            t++;

        ans += t-i+1;
    }

    cout << ans << endl;
    return 0;
}