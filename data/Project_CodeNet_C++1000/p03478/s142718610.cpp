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
    int n, a, b;
    cin >> n >> a >> b;
    
    int ans = 0;
    forn(i, 1, n+1) {
        int x = i, sum = 0;
        while (x) {
            sum += x%10;
            x /= 10;
        }
        if (sum >= a && sum <= b) ans += i;
    }
    cout << ans << endl;
}