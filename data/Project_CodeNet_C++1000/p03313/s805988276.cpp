#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = 18;

int n;
int best[1<<N][3];

void insert(int mask, int val){
    auto a = best[mask];
    a[2] = val;
    if (a[2] > a[1]) swap(a[2], a[1]);
    if (a[1] > a[0]) swap(a[1], a[0]);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    forn(i,1<<n) {
        int x; cin >> x;
        insert(i,x);
    }
    forn(i,n) {
        forn(mask, 1<<n) if ((mask>>i)&1) {
            int nmask = mask - (1<<i);
            forn(j,2) insert(mask, best[nmask][j]);
        }
    }


    for (int k = 2; k <= (1<<n); k++) {
        int ans = 0; 
        forn(i,n+1) if ((k>>i)&1) {
            int nk = (((k>>i) - 1) << i) + (1<<i) - 1;
            ans = max(ans, best[nk][0] + best[nk][1]);
        }
        cout << ans << '\n';
    }

    return 0;
}
