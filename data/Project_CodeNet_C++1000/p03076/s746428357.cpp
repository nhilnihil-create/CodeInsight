#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
int a, b, c, d, e;
int main() {
    vector<int> a(5);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num, min = 9, idx = 0;
    rep(i, 0, 5) {
        cin >> num;
        int keta = num % 10;
        if(keta < min && keta != 0) {
            min = keta;
            idx = i;
        }
        a[i] = num;
    }
    // lossを求める
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        if(i == idx) {
            sum += a[i];
        } else if(a[i] % 10 == 0) {
            sum += a[i];
        } else {
            // cout << (10 - (a[i] % 10)) + a[i] << endl;

            sum += (10 - (a[i] % 10)) + a[i];
        }
    }
    cout << sum << endl;
    return 0;
}
