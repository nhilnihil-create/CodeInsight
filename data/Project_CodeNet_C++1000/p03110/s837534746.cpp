#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    double total = 0;

    for(int i=0; i<N; i++) {
        double x;
        string u;
        cin >> x >> u;
        if(u == "BTC") {
            x *= 380000;
        }
        total += x;
    }
    cout << total << endl;
}

