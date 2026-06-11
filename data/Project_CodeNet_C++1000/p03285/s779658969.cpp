#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int N;
    cin >> N;

    int res = false;

    for (int i = 0; i <= N ; i += 4) {
        if ((N - i) % 7 == 0) {
            res = true;
        }
    }

    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
}
