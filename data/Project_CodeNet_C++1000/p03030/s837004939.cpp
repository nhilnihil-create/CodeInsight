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
    tuple<string, int, int> v[n];
    forn(i, 0, n) {
        string s;
        int p;
        cin >> s >> p;
        v[i] = {s, -p, i+1};
    }
    sort(v, v+n);
    forn(i, 0, n) {
        cout << get<2>(v[i]) << endl;
    }
}
