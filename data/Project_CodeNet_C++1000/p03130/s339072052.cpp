#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<ll> cnt(5, 0);
    Rep (i, 6) {
        ll a;
        cin >> a;
        cnt[a]++;
    }

    Rep (i, 5) {
        if (cnt[i] >= 3) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}