#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e10
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll>a(n, 0);
    unordered_map<ll, ll>ct;
    REP(i, n) {
        cin >> a[i];
        ct[a[i]]++;
    }

    ll ans = 0;

    for (auto i : ct) {
        if (i.first > i.second){
            ans += i.second;
        }
        else if (i.first < i.second){
            ans += i.second - i.first;
        }
    }

    cout << ans << endl;
}
        
