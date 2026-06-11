#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k; cin >> n >> k;

    if (n % k == 0)
        puts("0");
    else
        puts("1");
}