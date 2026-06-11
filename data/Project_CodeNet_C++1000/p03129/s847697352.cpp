#include <bits/stdc++.h>

using namespace std;


int main() {
    int n,k;
    cin >> n >> k;
    int c = n / 2;
    if(n % 2 == 1) {
        c++;
    }
    if(c >= k) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}