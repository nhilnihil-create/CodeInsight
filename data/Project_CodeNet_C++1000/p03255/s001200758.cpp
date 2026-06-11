#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// ordered_set X;
// *X.find_by_order(i) = ith largest element (counting from zero)
// X.order_of_key(k) = number of items in X < k (strict lt)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll answer(vll& dists, ll X, int k, vll& partials) {
    int N = sz(dists);

    ll total = (N+k)*X;
    for (int i=0;i<N;i+=k) {
        int left = i;
        int right = min(i+k, N);

        int ind = (i/k)+1;
        ll coeff = 0;
        if (ind == 1) coeff = 5;
        else coeff = 2*ind + 1;

        total += coeff*(partials[right] - partials[left]);
        if (total > 1e18) return 1e18;
    }

    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    ll X;
    cin >> N >> X;

    vll dists(N);
    for (int i=0;i<N;i++) cin >> dists[i];

    sort(all(dists));
    reverse(all(dists));
    
    vll partials(N+1, 0);
    for (int i=0;i<N;i++) partials[i+1] = partials[i] + dists[i];

    ll best_total = 2000000000000000000LL;
    for (int k=1;k<=N;k++) {
        ll cur_total = answer(dists, X, k, partials);
        best_total = min(cur_total, best_total);
    }
    cout << best_total << endl;

    

    return 0;
}
