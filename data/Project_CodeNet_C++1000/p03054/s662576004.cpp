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
#define P pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */
const int MAX_N = 200001;
char takas[4][MAX_N], aokis[4][MAX_N]; //LRUDの順

int main() {
    int H, W, N; cin >> H >> W >> N;
    P start; cin >> start.first >> start.second;
    string taka, aoki; cin >> taka >> aoki;
    map<char, int> m;//(h, w)
    m['L'] = -1, m['R'] = 1, m['U'] = -1, m['D'] = 1, m['x'] = 0;
    char c[4][2] = {{'L', 'R'}, {'R', 'L'}, {'U', 'D'}, {'D', 'U'}};
    rep(i, 4) {
        rep(j, N) {
            if(taka[j] == c[i][0]) takas[i][j] = c[i][0];
            else takas[i][j] = 'x';
            if(aoki[j] == c[i][1]) aokis[i][j] = c[i][1];
            else aokis[i][j] = 'x';
        }
    }
    P peni[4] = {mp(1, W), mp(W, 1), mp(1, H), mp(H, 1)};
    rep(i, 4) {
        int score = ((i < 2) ? start.second : start.first);
        bool ok = false;
        rep(j, N) {
            score += m[takas[i][j]];
            if(i % 2 == 0) if(peni[i].first > score) ok = true;
            if(i % 2 == 1) if(peni[i].first < score) ok = true;
            if(score != peni[i].second) score += m[aokis[i][j]];
        }
        if(ok) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
