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
    int n;
    cin >> n;
    ll ans = 0, x = 1e8;
    while (n--) {
        string a, b;
        cin >> a >> b;
        if (b == "JPY") {
            ans += stoll(a)*x;
        } else {
            ll i = stoll(a.substr(0, SZ(a)-9));
            ll j = stoll(a.substr(SZ(a)-8));
            ans += (i*x+j)*380000.0;
        }
    }
    cout << fixed << setprecision(6) << double(ans)/x << endl;
}