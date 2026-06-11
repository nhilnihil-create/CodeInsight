#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    vector<vector<int>>G(N);
    rep(i, N - 1) {
        int a, b; cin >> a >> b;
        G[--a].pb(--b); G[b].pb(a);
    }
    int c[N];
    rep(i, N) cin >> c[i];
    sort(c, c + N, greater<int>());
    queue<int> Q;
    Q.push(0);
    int i = 0;
    vector<int> score(N, -1);
    while(!Q.empty()) {
        int q = Q.front(); Q.pop();
        score[q] = c[i], ++i;
        for(int next : G[q]) {
            if(score[next] == -1) Q.push(next), score[next] = 0;
        }
    }
    int sum = 0;
    rep(i, N - 1) {
        sum += c[i + 1];
    }
    cout << sum << endl;
    rep(i, N) {
        cout << score[i] << ' ';
    }
    cout << endl;
}
