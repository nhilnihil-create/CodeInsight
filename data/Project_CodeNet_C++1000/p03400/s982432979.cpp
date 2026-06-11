#include <bits/stdc++.h>

using namespace std;


int isp(int x) {
    for (int i = 2; i * i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    int d, x;
    cin >> n >> d >> x;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        x += (d+a-1) / a;
    }
    cout << x << endl;
}
