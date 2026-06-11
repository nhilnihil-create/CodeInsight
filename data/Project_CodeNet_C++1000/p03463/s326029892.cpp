#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int d = b - a - 1;
    if(d % 2 == 0)cout << "Borys" << endl;
    else cout << "Alice" << endl;
    
}