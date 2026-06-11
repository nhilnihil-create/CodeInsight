#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)


int main() {
    int n, a, b;
    cin >> n >> a >> b;
    printf("%d %d\n", min(a,b), max(0, a+b-n));
}
