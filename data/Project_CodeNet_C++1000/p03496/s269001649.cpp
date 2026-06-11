#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i];
        b[i] = a[i];
    }    
    sort(b.begin(), b.end());

    int MAX = b[n-1];
    int MIN = b[0];

    if(0 <= MIN) {  // aが非負整数のみからなる場合
        cout << n-1 << "\n";
        for(int i = 1; i < n; i++) {
            cout << i << " " << i+1 << "\n";
        }
    }
    else if(MAX <= 0) {  // aが0以下の整数のみからなる場合
        cout << n-1 << "\n";
        for(int i = n; i > 1; i--) {
            cout << i << " " << i-1 << "\n";
        }
    }
    else {  // aに正の数も負の数も含まれる場合
        cout << 2*n-1 << "\n";
        int pos;
        if(MAX >= abs(MIN)) {  // すべての数にMAXを足せばaを非負整数のみにできる
            rep(i, n) {
                if(a[i] == MAX) {
                    pos = i+1;
                    break;
                }
            }
            for(int i = 1; i <= n; i++) {
                cout << pos << " " << i << "\n";
            }
            for(int i = 1; i < n; i++) {
                cout << i << " " << i+1 << "\n";
            }
        }
        else {  // すべての数にMINを足せばaを0以下の整数のみにできる
            rep(i, n) {
                if(a[i] == MIN) {
                    pos = i+1;
                    break;
                }
            }
            for(int i = 1; i <= n; i++) {
                cout << pos << " " << i << "\n";
            }
            for(int i = n; i > 1; i--) {
                cout << i << " " << i-1 << "\n";
            }
        }
    }

    return 0;
}