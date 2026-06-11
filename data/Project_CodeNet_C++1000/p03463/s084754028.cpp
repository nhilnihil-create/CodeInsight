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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int A, B;
    cin >> N >> A >> B;

    if ((B+A) % 2 == 0) cout << "Alice" << endl;
    else cout << "Borys" << endl;

    return 0;
}