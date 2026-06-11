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
    int n, m;
    cin >> n >> m;
    bitset<30> v[n];
    forn(i, 0, n) {
        int k;
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            v[i][a-1] = 1;
        }
        if (i) v[i] &= v[i-1];
    }
    cout << v[n-1].count() << endl;
}
