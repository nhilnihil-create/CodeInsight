#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int k;
    cin >> k;

    int ans = 0;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= k; j++) {
            if ((i%2 == 0) && (j%2 ==1)) ans++;
            else if ((i%2 == 1) && (j%2 == 0)) ans++;
        }   
    }
    cout << ans/2 << endl;
    return 0;
}