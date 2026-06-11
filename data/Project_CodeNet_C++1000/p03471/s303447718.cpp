#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n, y;
    cin >> n >> y;
    rep(i, n+1) {
        for(int j = 0; j <= n-i; j++) {
            int k = n - i - j;
            if(j * 10000 + i * 5000 + k * 1000 == y) {
                cout << j << ' ' << i << ' ' << k << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;

    return 0;
}