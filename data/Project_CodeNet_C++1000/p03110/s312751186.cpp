#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define all(a) a.begin(), a.end()
#define All(a) a.rbegin(), a.rend()
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.precision(5), cout << fixed
int main() {
    ios;
    int n;
    double sum = 0;
    cin >> n;
    while (n--) {
        double a;
        string t;
        cin >> a >> t;
        if (t[0] == 'B')
            sum += (a * 380000);
        else
            sum += a;
    }
    cout << sum << '\n';

    return 0;
}