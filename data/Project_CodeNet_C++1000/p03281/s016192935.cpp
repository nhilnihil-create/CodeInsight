#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans_count = 0;

    for(int i=1; i<=n; i++) {
        int div_count = 0;
        for(int j=1; j <= i; j++) {
            if(i % j == 0 && i % 2 == 1) div_count++;
        }
        if(div_count == 8) ans_count++;
    }
    cout << ans_count << endl;
}
