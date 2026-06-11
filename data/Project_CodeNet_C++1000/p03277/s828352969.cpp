/**
 *    Author:  "Robin Singh" !!!
**/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define mp make_pair
#define str string 
#define szz(v) ((int)(v).size())  
#define fr(i, j, k) for(int i = j; i < k; i++)     // 0 -> n-1 (i,0,n)
#define bk(i, j, k) for(int i = j-1; i >= k; i--)  // n-1 -> 0 (i,n,0)
#define frit(it, a) for(__typeof((a).begin()) it = a.begin(); it != a.end(); ++it)
#define mem(ptr)  memset(ptr, 0, sizeof ptr)  // use fill() for value other than 0
#define rtn return 
#define nl "\n"      // avoid endl
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector< pair<int,int> > vpii;
typedef vector< pair<ll, ll> > vpll;
const long long mod = 1e9+7;
const ld eps = 1e-9;
const ll INF = (1LL<<61);
const int inf = (1<<30);
//-------------------------------------------------------------------------------------------------------------
#define dbg( args...) { vector<string> _v = split( #args, ','); err( _v.begin(), args); cerr << '\n'; }
vector<string> split( const string& s, char c) { vector<string> v; stringstream ss( s); string x; 
while ( getline( ss, x, c)) v.emplace_back(x); return move(v); }
void err( vector<string>::iterator it) { } 
template<typename T, typename... Args>
void err( vector<string>::iterator it, T a, Args... args) {
    cerr << it -> substr( ( *it)[0] == ' ', it -> length()) << " = " << a << '\t'; err( ++it, args...); }
//-------------------------------------------------------------------------------------------------------------

const int nn = 3e5;
int bit[nn], a[nn], n;
ll tot;

void update(int ind){
    for(int i=ind; i<nn; i += (i & -i))
        bit[i]++;
}

int query(int ind){
    int res = 0;
    for(int i=ind; i>0; i -= (i & -i))
        res += bit[i];
    return res;
}

bool chk(int med){
    fill(bit, bit+nn, 0);
    ll res = 0;
    int cnt = n+1;                               // to avoid -ve sum
    update(cnt);                                // if at first element >= med, (1, 1) is one segment
    for(int i=0; i<n; i++){
        if(a[i] >= med) cnt++;
        else cnt--;
        res += query(cnt);                  // all place where value is <= cnt => contribution from that pos
        update(cnt);                       // to here is 0 or +ve => (>= element) >= (< element) in (l(varying).....r)
    }                                      // (>= element) >= (< element) is observation according as def. of median
    
    // res must be >= tot/2 (equality) // as def. of median is (n/2) + 1
    
    if(2 * res >= tot) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    int ans;
    
    tot = 1LL * n * (n+1)/2;                     // total length = n(size=1) + n-1(size=2) + n-2 ...
    
    for(int i=0; i<n; i++) cin >> a[i];
    
    int l = 0, r = 1e9;
    while(l <= r){
        int mid = (l + r)/2;
        if(chk(mid)) {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    
    cout << ans;
    return 0;
}

/* Logic : 
if any mid i.e median comes in more than or equal to tot/2 times in segment (l...r) then that can be a possibility
i.e. this mid <= ans (median).
e.g. 1 2 3 3, satisfy both for 2 and 3, but ans = 3 according as definition
so we go right just to find the first median which satisfies this condition
Also, any value > ans will not be answer (as we are using binary search) but that value will not fit in our array
as we are taking max that is satisfying
*/