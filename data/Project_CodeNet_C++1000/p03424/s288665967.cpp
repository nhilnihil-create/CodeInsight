#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    set<char> c;
    cin >> N;
    rep(i, N) {
        char S;
        cin >> S;
        c.insert(S);
    }

    if (c.size() == 3) {
        printf("Three\n");
    }
    else {
        printf("Four\n");
    }
}