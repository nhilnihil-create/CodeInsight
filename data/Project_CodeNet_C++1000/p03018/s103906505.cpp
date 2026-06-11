#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;

typedef long long LL;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> v;
    for(int i = 0; i < s.size(); ++i) {
        if(i + 1 < s.size() && s[i] == 'B' && s[i + 1] == 'C') {
            v.pb(1);
            i++;

        } else {
            if(s[i] == 'A') {
                v.pb(2);

            } else {
                v.pb(0);

            }
        }
    }

    LL res = 0;
    int bcc = 0;
    for(int i = v.size() - 1; i >= 0; --i) {
        if(v[i] == 2) {
            res += bcc;

        } else if(v[i] == 1){
            ++bcc;

        } else {
            bcc = 0;

        }
    }
    cout << res << endl;
    return 0;
}
