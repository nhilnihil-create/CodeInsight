#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define pi 3.14159265358979323
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    string s;
    cin >> s;
    if (s.size() == 2) {
        cout << s << endl;
        return 0;
    }
    else {
        reverse(s.begin(), s.end());
        cout << s << endl;
        return 0;
    }
}