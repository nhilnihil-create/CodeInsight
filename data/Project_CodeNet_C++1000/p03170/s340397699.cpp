#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int a[n];
    forn(i, 0, n) {
        cin >> a[i];
    }
    
    bool dp[k+1] = {};
    forn(i, 1, k+1) {
        for (auto &j : a) {
            if (i-j >= 0) {
                dp[i] |= !dp[i-j];
            }
        }
    }
    if (dp[k]) cout << "First\n";
    else cout << "Second\n";
}
