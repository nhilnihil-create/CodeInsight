#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int a,b,c;
    int n;
    int sum = 0;
    int count = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> n;

    for(int i=0; i<=a; i++) {
        for(int j=0; j<=b; j++) {
            for(int k=0; k<=c; k++) {
                sum = 500 * i + 100 * j + 50 * k;
                if (sum == n) count++;
            }
        }

        sum = 0;
    }

    cout << count << endl;
}

