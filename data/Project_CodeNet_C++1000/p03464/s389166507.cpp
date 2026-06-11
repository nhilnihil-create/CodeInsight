#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

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
int main(){
    int K;
    cin >> K;
    vll A(K);

    for (int i=0;i<K;i++) cin >> A[i];

    reverse(A.begin(), A.end());

    ll low = 2;
    ll high = 2;

    for (ll a: A) {
        ll lowi = (low + a-1) / a;
        ll highi = high / a;

        if (lowi > highi) {
            cout << -1 << endl;
            return 0;
        }

        low = a*lowi;
        high = a*highi + a-1;

    }

    cout << low << " " << high << endl;
    
}
