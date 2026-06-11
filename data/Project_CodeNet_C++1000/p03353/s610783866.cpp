#include <bits/stdc++.h>
#include <stdio.h>

#define INF 1e18
#define REP(i, n) for (int i=0; i<n; i++)
#define print(x) cout << x << endl
#define debug(x) cout << #x << " = "<< x << endl

const double PI=3.141592653589793238462643383279502884197169399375105820974944;

typedef long long ll;

using namespace std;

void solve() {
    string S;
    cin >> S; 
    int K;
    cin >> K;
    map<string, int> m;
    for (int i = 1; i < S.length()+1; i++) {
        if (S.length() > 50 && i > 10) {
            break;
        }
        for (int j = 0; j < S.length()-i+1; j++) {
            string sub = S.substr(j, i);
            m[sub] = 1;
        }
    }
    int cnt = 0;
    for (auto item : m) {
        cnt++;
        if (cnt == K) {
            print(item.first);
            break;
        }
    }

}

signed main() {
    solve();
}
