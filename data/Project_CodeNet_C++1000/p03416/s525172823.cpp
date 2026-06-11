#include <bits/stdc++.h>
using namespace std;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
 
int main() {
    int a, b, c = 0;
    cin >> a >> b;

    rep2(i, a-1, b) {
    int j = i + 1;

    if ((j % 10 == j / 10000) && (j / 1000 % 10 == j % 100 / 10)) {
       c++;
    }
    }
    cout << c << endl;
}