
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int a = n / 100;
    int b = n % 100;
    if (a <= 12 && a > 0) {
        if (b <= 12 && b > 0) {
            cout << "AMBIGUOUS" << endl;
        } else {
            cout << "MMYY" << endl;
        }
    } else {
        if (b <= 12 && b > 0) {
            cout << "YYMM" << endl;
        } else {
            cout << "NA" << endl;
        }
    }

    return 0;
}

