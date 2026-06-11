#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define maxs(x,y) x = max(x, y)
#define mins(x,y) x = min(x, y)
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    string S;
    cin >> S;

    vector<int> vec(26, 0);

    if (S.size() == 26) {
        if (S == "zyxwvutsrqponmlkjihgfedcba") {
            cout << -1 << endl;
            return 0;
        }
        string T = S;
        next_permutation(ALL(S));
        string ans = "";
        // cout << S << endl;
        
        for(int i = 0; i < S.size(); i++) {
            ans += S[i];
            if (S[i] > T[i]) {
                break;
            }
        }
        cout << ans << endl;
        return 0;
    }

    for(int i = 0; i < S.size(); i++) {
        vec[S[i] - 'a']++;
    }

    char ans;
    for(int i = 0; i < 26; i++) {
        if (vec[i] == 0) {
            ans = 'a' + i;
            break;
        }
    }
    cout << S << ans <<endl;


    //cout << ans << endl;
    return 0;
}