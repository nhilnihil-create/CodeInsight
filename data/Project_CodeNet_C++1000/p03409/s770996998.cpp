#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(a) sort(a.begin(), a.end())
const int INF = 1<<30;
const ll MOD = 1000000007;

int main(void) {

    int N; cin >> N;
    vector<pair<int, int> > ab(N); rep(i, N) cin >> ab[i].second >> ab[i].first;
    vector<pair<int, int> > cd(N); rep(i, N) cin >> cd[i].first >> cd[i].second;

    Sort(ab); Sort(cd);
    int ans = 0;
    vector<bool> vb(N, false);

    rep (i, N) {

        pair<int, int> tmp;
        int flg = -1;

        rep(j, ab.size()) {
            if (ab[j].second < cd[i].first && ab[j].first < cd[i].second && !vb[j]) flg = j;
        }

        if (flg != -1) {
            ans++;
            vb[flg] = true;
        }
        // ab.erase(ab.begin() + flg);
    }

    cout << ans << endl;
    return 0;
}