#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b;
    string s;
    cin >> a >> b >> s;
    
    bool ok = true;
    
    if (SZ(s) != a+b+1) {
        cout << "No\n";
        return 0;
    }
    
    forn(i, 0, a) {
        ok &= isdigit(s[i]);
    }
    ok &= s[a] == '-';
    forn(i, a+1, SZ(s)) {
        ok &= isdigit(s[i]);
    }
    
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}
