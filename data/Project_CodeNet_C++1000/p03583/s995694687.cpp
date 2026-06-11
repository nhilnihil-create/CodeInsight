#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    FOR(a, 1, 3501) FOR(b, 1, 3501) {
        ll bunshi = n * a * b;
        ll bunbo = 4 * a * b - (a + b) * n;
        if(bunbo > 0 && bunshi % bunbo == 0 && bunshi / bunbo > 0) {
            cout << a << " " << b << " " << bunshi / bunbo << endl;
            return 0;
        }
    }
    return 0;
}