#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define endl '\n'
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

using ll = long long;
using P = pair<ll, ll>;

/*追加部分*/



/*main関数*/

int main() {
FASTIO;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    int sum_a = 0, sum_b = 0;

    for(int i = 0; i < n; i++){
        i%2 == 0 ? sum_a += a[i] : sum_b += a[i];
    }

    cout << sum_a - sum_b << endl;

return 0;
}