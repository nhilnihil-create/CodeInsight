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
const ll INF = 1e9 + 8;
const ll MOD = 1e9 + 7;
const ll LLINF = 1e18;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rnr(i,a,b) for(int i=int(a);i>=int(b);i--)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

bool isOk(vector<int> result, vector<int> material) {
    sort(all(result));
    sort(all(material));
    int j = 0;
    rep(i, material.size()) {
        if(material[i] == result[j]) {
            ++j;
        }
        if(j == result.size()) break;
    }
    return (j == result.size());
}

int main() {
    int n; cin >> n;
    vector<int> D(n);
    rep(i, n) cin >> D[i];
    int m; cin >> m;
    vector<int> T(m);
    rep(i, m) cin >> T[i];
    if(isOk(T, D)) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
}
