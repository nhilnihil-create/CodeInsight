#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N, D, X;
    cin >> N >> D >> X;
    int sum = 0;
    for (int i=0; i< N; i++) {
        int choco = 1;
        int A;
        cin >> A;
        int day = A + 1;
        int count = 1;
        while (day <= D) {
            choco += 1;
            count += 1;
            day = (count * A) + 1;
        }

        sum += choco;
    }

    cout << sum + X << endl;
    return 0;
}