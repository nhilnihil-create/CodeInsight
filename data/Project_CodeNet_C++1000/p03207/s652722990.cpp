#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int Max = 0;
    int sum = 0;

    cin >> num;

    for (int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        Max = max(Max, tmp);
        sum += tmp;
    }

    sum -= Max / 2;
    cout << sum;
    //
}
