#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;

    cin >> N;

    int a = N;
    int num = 1;

    while(a > 10) {
        num++;
        a /= 10;
    }

    a = N;
    int sum = 0;
    for(int i = 0; i < num; i++) {
        sum += a % 10;
        a /= 10;
    }

    if(N % sum == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
