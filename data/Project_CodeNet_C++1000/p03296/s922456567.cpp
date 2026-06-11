#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() { 
    int n;
    cin >> n;
    int count = 0;
    vector<int> a(n);
    int ca = 110;
    rep(i, n) cin >> a[i];
    rep(i, n) {
        if(i > 0) {
            if(a[i] == a[i - 1]) {
                count++;
                a[i] = ca;
                ca++;
            }
        }
    }
    cout << count << endl;
}
