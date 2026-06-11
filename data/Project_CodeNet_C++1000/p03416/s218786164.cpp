#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool isKaibun(int num) {
    vector<int> v(5);
    int i = 0;
    while(num) {
        v.at(i) = num % 10;
        num /= 10;
        ++i;
    }
    if (v.at(0) == v.at(4) && v.at(1) == v.at(3)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    int res = 0;
    for (int i = a; i <= b ; ++i) {
        if (isKaibun(i)) {
            ++res;
        }        
    }

    cout << res << endl;
    return 0;

}
