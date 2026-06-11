#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    string s;
    cin >> s;
    int N = s.size();
    int K;
    cin >> K;
    set<string> x;
    REP(i, N) {
        FOR(j, 1, min(K + 1, N - i + 1)) {
            string y = s.substr(i, j);
            if(x.find(y) == x.end()) {
                x.insert(y);
            }
        }
    }
    int M = x.size();
    vector<string> v;
    v.reserve(M);
    for(auto i : x) {
        v.push_back(i);
    }
    sort(ALL(v));
    cout << v[K - 1] << endl;
    return 0;
}
