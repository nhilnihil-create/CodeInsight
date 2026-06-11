/**
 *    Author: "Robin Singh" !!
 *    BrainyIsTheNewSexy    (CodeForces, CodeJam)
 *    rob_in_1              (All Other OJs)
**/

#include <bits/stdc++.h>
using namespace std;

#define dbg( args...) { vector<string> _v = split( #args, ','); err( _v.begin(), args); cerr << '\n'; }
vector<string> split( const string& s, char c) { vector<string> v; stringstream ss( s); string x; 
while ( getline( ss, x, c)) v.emplace_back(x); return move(v); }
void err( vector<string>::iterator it) { } 
template<typename T, typename... Args>
void err( vector<string>::iterator it, T a, Args... args) {
cerr << it -> substr( ( *it)[0] == ' ', it -> length()) << " = " << a << '\t'; err( ++it, args...); }

#define int long long
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define ff first
#define ss second
#define MP make_pair
#define szz(v) ((int)(v).size())  
#define fr(i, j, k) for(int i = j; i < k; i++)     
#define bk(i, j, k) for(int i = j-1; i >= k; i--)
#define mem(ptr, val)  memset(ptr, val, sizeof ptr)
#define sbit(n)  __builtin_popcount(n)
#define nl "\n"

typedef long double ld;
typedef pair<int, int> pii;
typedef vector <int> vi;
typedef vector < pair<int,int> > vpii;
const long double eps = 1e-9;
const int mod = 1e9+7;

pii dir[8] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1} , {-1, 1}, {1, -1} };

//*****************************************!Template Ends Here!******************************************//

const int nn = 2e5+5;

void solve(){
    int n;
    cin >> n;
    int k = -1;
    for(int i=1; i<=1000; i++){       // i <= n will give WA for n = 1, as k = 2 is answer for n = 1 (as 2 > 1, k > n)
        if(i * (i - 1)/2 == n){       // n = 1 => (1), (1) 2 sets
            k = i;
            break;
        }
    }
    // k subsets of size (k-1)  [for one set one common from each k-1 set]
    // tot elements = k * (k-1)/2  [ /2  as all elements appear twice]
    if(k == -1){
        cout << "No";
        return;
    }
    cout << "Yes\n" << k << nl;

    int cur = 1;
    vector <int> s[k];

    for(int i = 0; i < k; i++){
        for(int j = i+1; j < k; j++){
            s[i].push_back(cur);
            s[j].push_back(cur++);
        }
    }
    for(int i=0; i<k; i++){
        cout << szz(s[i]) << ' ';
        for(int x : s[i]) cout << x << ' ';
        cout << nl;
    }
}

int32_t main(){
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}