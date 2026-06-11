#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int count = 0;

    for(int i=n; i <= m; i++) {
        if(i / 10000 == i % 10 && i / 1000 % 10 == i % 100 / 10) {
            count++;
        }
    }
    cout << count << endl;
}
