#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int a, p;
    cin >> a >> p;
    cout << (a * 3 + p) / 2 << endl;
}