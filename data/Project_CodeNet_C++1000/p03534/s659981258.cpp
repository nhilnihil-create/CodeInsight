#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define getBit(x,i) (x&(1<<i))
#define setBit(x,i) (x|(1<<i))
#define mem(A,N) memset(A,N,sizeof(A))
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define rep(i, x, y)  for(int i = x; i < y; ++i)
#define Rep(i, x, y)  for(int i = x; i <= y; ++i)
#define srep(i, x, y) for(int i = x; i > y; --i)
#define sRep(i, x, y) for(int i = x; i >= y; --i)
#define all(v) v.begin(),v.end()
#define Sort(x) sort(x.begin(), x.end())
#define f1(i,n) for (int i=1; i<=n; i++)
#define f0(i,n) for (int i=0; i<n; i++)
#define SZ(x) ((int)(x).size())
#define LEN(x) ((int)(x).length())
#define fi first
#define se second

#define linf 0x7FFFFFFFFFFFFFFF
#define inf 0x7FFFFFFF
#define mod 1000000007
#define eps 1e-9
#define Pi 3.14159265358979323846

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl
#define write(x) cerr << #x << " = " << (x) << ", "
#define writeI0 cerr << "i = " << 0 << ", "
#define dumpI0 cerr << "i = " << 0 << endl
#define printSet(x) for(auto it = s.begin(); it!=s.end(); it++) (it==s.begin())? cout << *it : cout << ' ' << *it; cout << endl;
#define printVector(x) for(auto it = x.begin(); it!=x.end(); it++) (it==x.begin())? cout << *it : cout << ' ' << *it; cout << endl;

// ***************** End Of Template ********************

int c[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin >> s;
    rep(i, 0, LEN(s)) {
        c[ s[i]-'a' ]++;
    }
    int mn = 1e9;
    rep(i, 0, 3) {
        mn = min(mn, c[i]);
    }

    int d = 0;
    rep(i,0,3) {
        c[i] -= mn;
        if(c[i] > 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}

