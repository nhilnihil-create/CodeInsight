#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define OP ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for(int i = (a); i <=(n); ++i)
#define repst(i, n) for(auto it = n.begin(); it != n.end(); ++it)
#define Repr(i, a, n) for(int i = (n); i >= (a); --i)
typedef long long ll;
typedef std::vector<int> vi;
typedef std::pair<int, int> pii;
const int inf = int(1e9);
const int mod = inf + 7;
const double PI = acos(-1.0);
using namespace std;
const int N = 1e5 + 155;
template<typename T>
inline void read(T&x){
    x=0;int f=1;char ch = getchar();
    while(ch<'0' ||ch>'9'){ if(ch=='-')f=-1;ch=getchar(); }
    while(ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
    x*=f;
}

void solve(){
    string s;
    cin >> s;
    int ans = sz(s);
    int temp = ans;
    Rep(i, 1, sz(s) - 1){
        if(s[i] != s[i - 1]) ans = min(ans, max(i, temp - i));
    }
    cout << ans;
}
 
int main(){
    OP
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t = 1;
    while(t--)
    solve();
    return 0;
}