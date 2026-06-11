#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dig(int x, int y) {
    rep(i, y - 1) x /= 10;
    return x % 10;
}

int main() {
    string s;
    cin >> s;
    int num = stoi(s);
    
    int a = dig(num, 1) + 10 * dig(num, 2) ;
    int b = dig(num , 3) + 10 * dig(num, 4);

    if (a == 0) {
        if (b == 0 || b >= 13) cout << "NA";
        else cout << "MMYY";
    }

    else if (b == 0) {
        if (a >= 13) cout << "NA";
        else cout << "YYMM";
    }

    else if(a >= 13  && b >= 13) cout << "NA";

    else if (a >= 13 && b < 13) cout << "MMYY";

    else if (a < 13 && b >= 13) cout << "YYMM";

    else cout << "AMBIGUOUS";
}