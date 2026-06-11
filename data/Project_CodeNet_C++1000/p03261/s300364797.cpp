#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
#define fi first
#define se second
#define all(uiet) uiet.begin(),uiet.end()
#define read(UIET) for(int i = 0; i < n; ++i) cin >> UIET[i]
#define out(UIET) for(int i = 0; i < n; ++i) cout << UIET[i]
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vpp vector<pair< int, int > >
#define pll pair<int , int >
#define ppll pair < pll , pll >
#define debug(n1) cout << n1 << endl
#define len(a) ((int) (a).size())
#define endl "\n"
#define mod 1000000007
const int INF=(1LL<<60)-1;
const int MAXN = 1000001;
vector<int> adj[MAXN];
int power(int x, int y, int p = mod){ 
    int res = 1; 
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0) {  
        if (y & 1) res = (res*x) % p; 
        y = y >> 1;
        x = (x * x) % p;   
    } 
    return res; 
} 
int modFact(int n, int p = mod) 
{ 
    if (n >= p) 
        return 0; 
  
    int result = 1; 
    for (int i = 1; i <= n; i++) 
        result = (result * i) % p; 
  
    return result; 
} 
int32_t main(){
    SPEED;
    int n;
    cin >> n;
    string s[n];
    set<string> dif;
    for(int i = 0; i < n; ++i){
        cin >> s[i];
        dif.insert(s[i]);
    }
    if(len(dif) == n){
        for(int i = 0; i < n - 1; ++i){
            int x = len(s[i]);
            if(s[i][x - 1] != s[i + 1][0]){
                cout << "No";
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

}
// check indices of loop
// check for overflow
