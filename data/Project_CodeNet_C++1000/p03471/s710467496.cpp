#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define ll long long
using namespace std;



int main() {

    int n,y; cin >> n >> y;
    int ans = false;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(n-i-j >= 0) {
                int sum;
                sum = i * 10000 + j * 5000 + (n-i-j) *1000;
                if(sum == y) {
                    ans = true;
                    cout << i << ' ' << j << ' ' << n-i-j << endl;
                    break;
                }
            }
        }
        if(ans) break;
    }

    if(!ans) cout << "-1 -1 -1" << endl;

    return 0;
}



