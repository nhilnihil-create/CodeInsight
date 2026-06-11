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
    int ans = 0;
    rep(i, n) {
        int a;
        cin >> a;
        int cou = 0;
        bool ok = 1;
        while(ok) {
            if(a%2 == 1) break;
            a /= 2;
            cou++;
        }
        ans += cou;
    }
    cout << ans << endl;

    return 0;
}