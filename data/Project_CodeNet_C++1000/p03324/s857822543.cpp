#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)

int fn(int n) { // nを100で割り切れる回数
    int count = 0;
    while (1) {
        if (n % 100 == 0) {
            n /= 100;
            count++;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    int d, n;
    cin >> d >> n;

    int i = 0; int num = 0;
    while (num != n) {
        if (fn(i+1) == d) num++;
        i++;
    }
    cout << i << endl;
}