#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair< int, int >;

bool betemp(string sleft, string sright, int left, int right) {
    if (sleft == sright)
        return (right - left) % 2 == 1;
    else
        return (right - left) % 2 == 0;
}

int main() {
    int N;
    cin >> N;

    string vac = "Vacant";
    string sleft, sright, str;
    int left = 0, right = N / 2;

    cout << left << endl;
    cin >> sleft;
    if (sleft == vac) return 0;
    cout << right << endl;
    cin >> sright;
    if (sright == vac) return 0;

    if (!betemp(sleft, sright, left, right)) {
        swap(sleft, sright), left = right, right = N;
    }

    while (right - left > 1) {
        int mid = (left + right) / 2;
        cout << mid << endl;
        cin >> str;
        if (str == vac) return 0;
        if (betemp(sleft, str, left, mid)) {
            sright = str, right = mid;
        } else {
            sleft = str, left = mid;
        }
    }
}