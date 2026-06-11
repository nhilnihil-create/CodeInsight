#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int gcd(int a, int b) {
    if(a % b == 0) return b;
    else return(gcd(b, a % b));
}

vector<int> divisor(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    int x = gcd(a, b);
    vector<int> y = divisor(x);
    cout << y[k - 1] << endl;
    return 0;
}