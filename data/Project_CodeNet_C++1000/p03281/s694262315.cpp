#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n; cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0) continue;
        int cnt = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0) cnt++;
        }
        if(cnt == 8) ans++;
    }
    cout << ans << endl;

    return 0;
}
