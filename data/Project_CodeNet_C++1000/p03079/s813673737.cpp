#include <bits/stdc++.h>
using namespace std;
int main () {
    set<int> s;
    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    if (s.size() == 1) {
        puts("Yes");
    }
    else {
        puts("No");
    }
}