#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define FF first
#define SS second
#define INF 2e18;
#define mp make_pair
#define ll long long
#define pii pair<int,int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define endl '\n'
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define sz(s) (int)s.size()
#define all(x) x.begin(), x.end()
typedef long double ld;

const int N = 2e5 + 5;
vector<int> v[40];
int lol[40];
int a[N], b[N];

signed main()
{
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    srand(time(NULL));
 
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    // n = 25;
    int c1 = 0, c2 = 0;
    int c3 = 0, c4 = 0;
    fr(i, 1, n) {
        cin >> a[i];
        // a[i] = ((ll)rand() * rand()) % (1 << 28);
    }
    fr(i, 1, n) {
        cin >> b[i];
        // b[i] = ((ll)rand() * rand()) % (1 << 28);
        for(int j = 0; j <= 35; j++) {
            int val = b[i] % (1LL << (j + 1));
            v[j + 1].pb(val);
        }
    }
    fr(i, 1, 36) {
        sort(all(v[i]));
    }
    int ans = 0;
    fr(i, 1, n) {
        for(int j = 0; j <= 35; j++) {
            int val = a[i] % (1LL << (j + 1));
            val = (1LL << (j + 1)) - val;
            int x = v[j + 1].end() - lower_bound(all(v[j + 1]), val);
            x &= 1;
            lol[j + 1] ^= x;
        }
    }
    fr(j, 0, 35) {
        c1 = c2 = c3 = c4 = 0;
        fr(i, 1, n){
            if(a[i] & (1LL << j)) c1++;
            else c2++;
            if(b[i] & (1LL << j)) c3++;
            else c4++;
        }
        if((c1 * c4 + c2 * c3) & 1) lol[j] ^= 1;
    }
    fr(i, 0, 36) {
        if(lol[i]) ans ^= (1LL << i);
    }
    cout << ans << endl;
    // int brute = 0;
    // fr(i, 1, n) {
    //     fr(j, 1, n) {
    //         brute ^= (a[i] + b[j]);
    //     }
    // }
    // cout << brute << endl;
    return 0;
}