#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int n; cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> odd(100001), even(100001);
    ll sum = n;
    for(int i = 0; i < 100001; i++) {
        odd[i].second = i;
        even[i].second = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(i % 2 == 0) odd[v[i]].first++;
        else even[v[i]].first++;
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    ll O = odd[100000].second, E = even[100000].second;
    if(O == E) {
        if(odd[100000].first == even[100000].first) {
            if(odd[99999].first > even[99999].first) sum -= odd[99999].first + even[100000].first;
            else sum -= odd[100000].first + even[99999].first;
        }
        else if(odd[100000].first > even[100000].first) sum -= odd[100000].first + even[99999].first;
        else sum -= odd[99999].first + even[100000].first;
    }
    else {
        sum -= (odd[100000].first + even[100000].first);
    }
    cout << sum << endl;
}