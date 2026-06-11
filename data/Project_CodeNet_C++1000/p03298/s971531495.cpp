#include <iostream>
#include <map>

using namespace std;
#define REP(i,n) for (int i = 0; i < n; ++i)

int N;
string S;
map<pair<string, string>, int> m;

int main() {
    cin >> N >> S;
    int all = (1<<N) - 1;
    REP (i, 1<<N) {
        string s, t;
        REP (j, N) {
            if (i>>(N-j-1) & 1) s += S[j];
            else t += S[j];
        }
        m[make_pair(s, t)]++;
    }

    long long ans = 0;
    REP (i, 1<<N) {
        string s, t;
        REP (j, N) {
            if (i>>(N-j-1) & 1) s += S[2*N-1-j];
            else t += S[2*N-1-j];
        }
        ans += m[make_pair(s, t)];
    }

    cout << ans << endl;
}