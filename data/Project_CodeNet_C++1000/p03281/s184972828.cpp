#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    cin >> n;
    int ans = 0;

    for(int i = 1; i <= n; i+=2) {
        int cou = 0;
        for(int j = 1; j <= i; j++) if(i % j == 0) cou++;
        if(cou == 8) ans++;
    }

    cout << ans << endl;

    return 0;
}   