#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   string n;
   cin >> n;

    if ((n[0] == n[1] && n[1] == n[2]) || (n[1] == n[2] && n[2] == n[3])) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}