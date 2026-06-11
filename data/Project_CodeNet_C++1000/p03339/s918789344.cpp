//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int nume = 0;
    int numw = 0;
    vector<int> a(n);
    rep(i, n) {
        a[i] = numw;
        if(s[i] == 'E') {
            nume++;
        }
        if(s[i] == 'W') {
            numw++;
        }
    }

    int ans = 1e9;
    nume = 0;
    numw = 0;
    for(int i = n-1; i>= 0; --i) {
        ans = min(ans, a[i] + nume);

        if(s[i] == 'E') {
            nume++;
        }
        if(s[i] == 'W') {
            numw++;
        }
    }

    cout << ans << endl;

    return 0;
}
