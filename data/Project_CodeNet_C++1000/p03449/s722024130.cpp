#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int>uenodan(N);
    vector<int>shitanodan(N);
    for (int i=0; i < N; i++) {
        cin >> uenodan.at(i);
    }

    for (int i=0; i < N; i++) {
        cin >> shitanodan.at(i);
    }

    int sum = 0;
    for (int i=0; i < N; i++) {
        int count = 0;
        for (int j=0; j <= i; j++) {
            count += uenodan[j];
        }

        for (int k=i; k < N; k++) {
            count += shitanodan[k];
        }

        if (count > sum) {
            sum = count;
        }
    }

    cout << sum << endl;
}