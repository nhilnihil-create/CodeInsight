#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359;
#define inf (1 << 21);
#define mod 1000000007;

int f(int n) {
    if (n % 2 == 0) {
        return n / 2;
    }
    else {
        return 3 * n + 1;
    }
}

int main() {
    int s; cin >> s;
    vector<bool> J(10000, false);
    int now = s, next, cnt = 1;
    J.at(s - 1) = true;
    while (true) {
        next = f(now);
        cnt++;
        if (J.at(next - 1) == false) {
            J.at(next - 1) = true;
            now = next;
        }
        else {
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}