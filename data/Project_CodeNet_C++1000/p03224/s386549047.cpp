#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 1e5 + 5;
vector<int> sub[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    ll k = 1;
    while((k * (k - 1)) / 2 < n) {
        k++;
    }
    if(((k * (k - 1)) / 2 > n)) {
        cout << "No" << '\n';
        return 0;
    }
    int id = 1;
    for(int i = 1; i <= k; i++) {
        for(int j = i + 1; j <= k; j++) {
            sub[i].push_back(id);
            sub[j].push_back(id);
            id++;
        }
    }
    cout << "Yes" << '\n';
    cout << k << '\n';
    fori(i, 1, k + 1) {
        cout << sub[i].size();
        for(auto &each : sub[i]) {
            cout << " " << each;
        }
        cout << '\n';
    }
    return 0;
}
