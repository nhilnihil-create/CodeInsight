#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int a, b; cin >> a >> b;
    int i = b - a - 1;
    cout << i*(i+1)/2 - a;
}
