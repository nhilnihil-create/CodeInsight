#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    int v = 2;
    int mod2 = 0, mod3 = 0, mod5 = 0;
    for (int i = 0; i < N-2; i++) {
        while (!(v % 2 == 0 || v % 3 == 0 || v % 5 == 0)) v++;
        mod2 = (mod2 + v) % 2;
        mod3 = (mod3 + v) % 3;
        mod5 = (mod5 + v) % 5;
        cout << v++ << ' ';
    }
    while (!((v % 2 == 0 || v % 3 == 0 || v % 5 == 0) && v % 5 == (5 - mod5) % 5)) v++;
    mod2 = (mod2 + v) % 2;
    mod3 = (mod3 + v) % 3;
    mod5 = (mod5 + v) % 5;
    cout << v++ << ' ';
    while (!(v % 2 == (2 - mod2) % 2 && v % 3 == (3 - mod3) % 3 && v % 5 == 0)) v++;
    cout << v << '\n';
    return 0;
}