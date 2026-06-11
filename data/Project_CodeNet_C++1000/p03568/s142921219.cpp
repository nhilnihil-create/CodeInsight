#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    cin >> n;
    int a[n];
    int ans = 1, bad=1;
    rep(i, n) {
        cin >> a[i];
        ans *= 3;
        if(a[i] % 2 == 0) bad *= 2;
    }
    cout << ans - bad << endl;
    return 0;
}