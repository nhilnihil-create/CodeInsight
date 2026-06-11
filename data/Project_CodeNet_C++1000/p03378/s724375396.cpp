#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<bool>ryoukinzyo(N+1, false);
    for (int i=0; i<M; i++) {
        int x;
        cin >> x;
        ryoukinzyo[x] = true;
    }

    int cost = 0;
    int n = X;
    while (n < N) {
        n = n + 1;
        if (ryoukinzyo[n]) {
            cost += 1;
        }
    }

    int sita_cost = 0;
    int l = X;
    while (l > 0) {
        l = l - 1;
        if (ryoukinzyo[l]) {
            sita_cost +=1;
        }
    }

    cout << min(cost, sita_cost) << endl;
    return 0;
}