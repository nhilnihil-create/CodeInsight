#include <bits/stdc++.h>
#define fin ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ii pair<int,int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fore(i,a,b) for(int i = a;i < b; i+= 1)
#define forr(i,a) for(int i = a; i >= 0; i--)
#define fori(i,m) for(auto i = m.begin(); i != m.end(); i++) 
#define w(t) while(t--)
#define sz(s) int(s.size())
#define cls(a,car) memset(a,car,sizeof (a))
#define what_is(x) cerr << #x << " is " << x << '\n'
#define FL freopen("in", "r", stdin),freopen("out", "w", stdout);
#define time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 3 * 1e5 + 5;
const ll mod = 998244353;
const int INF = INT_MAX;
const ll INFCAD  = ll(INT_MAX) * 2 + 1;
const double E = 1e-9;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
// fflush(stdout)
// cout << flush
// a + b = a ^ b + 2 * (a & b)  
int pre[N], suf[N];
int main(){
    //FL;
    fin;
    int n;
    string str;
    cin >> n >> str;
    fore(i, 0, sz(str))
        pre[i] = (str[i] == 'W');
    fore(i, 1, sz(str))
        pre[i] += pre[i - 1];
    for(int i = sz(str) - 1; i >= 0; i--)
        suf[i] = (str[i] == 'E');
    for(int i = sz(str) - 2; i >= 0; i--)
        suf[i] += suf[i + 1];
    int ans = 1e9;
    fore(i, 0, n){
        int aux_1 = 0;
        if(i)
            aux_1 = pre[i - 1];
        int aux_2 = 0;
        if(i + 1 < n)
            aux_2 = suf[i + 1];
        ans = min(ans,aux_2 + aux_1);
    }
    cout << ans << '\n';
    time;
    return 0;
}   