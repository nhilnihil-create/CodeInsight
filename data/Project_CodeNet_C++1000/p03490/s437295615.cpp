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

const int N = 8080;

bool tmp[N];
void update(bool a[], int d) {
    memset(tmp, 0, sizeof tmp);
    forn(i,N) if (a[i]) {
        int x = i+d;
        int y = abs(i-d);
        if (x < N) tmp[x] = 1;
        if (y < N) tmp[y] = 1;
    }
    memcpy(a, tmp, N);
}

bool can[2][N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    can[0][0] = can[1][0] = 1;
    string s; cin >> s; s += 'T';
    int x,y; cin >> x >> y;
    int axis = 0, cnt = 0;
    bool first = 1;
    for (char c : s) {
        if (c == 'T') {
            if (first) {
                x -= cnt;
                first = 0;
            }
            else if (cnt) update(can[axis], cnt);
            axis = 1-axis;
            cnt = 0;
        }
        else cnt++;
    }
    x = abs(x); y = abs(y); 

    bool ok = can[0][x] && can[1][y];
    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
