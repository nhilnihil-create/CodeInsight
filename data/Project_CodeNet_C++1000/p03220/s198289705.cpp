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
    int n, t, a;
    cin >> n >> t >> a;
    a *= 1000;
    t *= 1000;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    int ans = inf;
    int aans = 0;
    rep(i, n) {
        int sa = t - h[i] * 6;
        ans = min(ans, abs(sa - a));
        if(ans == abs(sa - a)) aans = i + 1;
    }

    cout << aans << endl;

    return 0;
}