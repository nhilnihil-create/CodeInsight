#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int n;
vector<pair<int, int> > ans;
vector<int> v[105];

int main(void) {
    cin >> n;

    for (int i=1; i<=(n/2); i++) {
        v[i].pb(i);
        v[i].pb(n-i+1-(n%2));
    }

    for (int i=1; i<n/2; i++) {
        for (int x : v[i]) for (int y : v[i+1]) ans.pb(mp(x, y));
    }

    if (n%2==1) {
        for (int x : v[n/2]) ans.pb(mp(n, x));
        if (n!=3) for (int x : v[1]) ans.pb(mp(n, x));
    } else {
        if (n!=4) for (int x : v[n/2]) for (int y : v[1]) ans.pb(mp(x, y));
    }

    cout << (int)ans.size() << endl;

    for (pair<int, int> pr : ans) printf("%d %d\n", pr.first, pr.second);

	return 0;
}
