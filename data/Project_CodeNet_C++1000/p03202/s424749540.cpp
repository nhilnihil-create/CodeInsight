#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << (a) << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = 2e5 + 10;
int n, a[N], ascending;

bool good(int b) {
    if (b == 1) return ascending;

    vector<pii> num;
    forn(i,n-1) {
        if (0) {
            int j = 0;
            forn(i,a[i]) {
                while (j < si(num) && num[j].first < i) ++j;
                if (j < si(num) && num[j].first == i) cerr << num[j].second;
                else cerr << 0;
            }
            cerr << endl;
        }

        if (a[i+1] <= a[i]) {
            int pos = a[i+1]-1;
            while (!num.empty() && num.back().first > pos) num.pop_back();

            while (!num.empty() && num.back() == mp(pos,b-1)) {
                num.pop_back();
                pos--;
            }
            if (pos < 0) return 0;
            if (!num.empty() && num.back().first == pos) num.back().second++;
            else num.eb(pos,1);
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    forn(i,n) cin >> a[i];

    ascending = 1;
    forn(i,n-1) ascending &= a[i] < a[i+1];

    int lo = 0, hi = n+2;
    while (lo+1 < hi) {
        auto mi = (lo+hi)/2;
        if (good(mi)) hi = mi; else lo = mi;
    }
    cout << hi << endl;

    return 0;
}
