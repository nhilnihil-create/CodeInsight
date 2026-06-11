#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if(c == 'Y') {
            puts("Four");
            return 0;
        }
    }
    puts("Three");
    return 0;
}