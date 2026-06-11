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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    forn(i, 0, n) {
        int j = i;
        while (j < n && (s[j] == 'A' || s[j] == 'C' || s[j] == 'G' || s[j] == 'T')) {
            j++;
        }
        ans = max(ans, j-i);
    }
    cout << ans << endl;
}
