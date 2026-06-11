#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();

    set<string> v;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            v.insert(s.substr(i, j));
        }
    }

    auto ite = v.begin();
    for(int i = 1; i < k; i++) ite++;
    cout << *ite << endl;
}
