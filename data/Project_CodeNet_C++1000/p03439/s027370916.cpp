#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << 0 << endl;
    string first;
    cin >> first;
    if (first == "Vacant") return 0;

    int l = 0, r = n;
    while (true) {
        int m = (l + r) / 2;
        cout << m << endl;

        string sex;
        cin >> sex;
        if (sex == "Vacant") break;

        if (m % 2 && sex != first || m % 2 == 0 && sex == first)
            l = m + 1;
        else
            r = m;
    }

    return 0;
}
