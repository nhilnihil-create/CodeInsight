#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N, M; cin >> N >> M;
    vector<int> k(M), p(M);
    Graph s(M);
    for(int i = 0; i < M; i++){
        cin >> k[i];
        for(int j = 0; j < k[i]; j++) {
            int S; cin >> S;
            s[i].push_back(S);
        }
    }
    for(int i = 0; i < M; i++) cin >> p[i];
    ll ans = 0;
    for(int i = 0; i < (1 << 10); i++) {
        bitset<10> bit(i);
        if(i == (1 << N)) break;
        bool judge = true;
        for(int u = 0; u < M; u++) {
            int cnt = 0;
            for(auto v: s[u]) if(bit.test(v - 1)) cnt++;
            if(cnt % 2 != p[u]) judge = false;
        }
        if(judge) ans++;
    }
    cout << ans << endl;
    return 0;
}