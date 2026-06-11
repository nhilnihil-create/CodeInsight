

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


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

/*
...  #......#####. #####
*/

int ans = 1000000000;
int x[200005];

int main(void) {
    int n;
    string s;
    cin >> n >> s;

    int w = 0, b = 0;
    rep(i, 0, n) if (s[i]=='.') w++;

    ans = min(ans, w);
    rep(i, 0, n) {
        if (s[i]=='.') w--;
        else b++;
        ans = min(ans, w+b);
    }
    
    cout << ans << endl;

	return 0;
}
