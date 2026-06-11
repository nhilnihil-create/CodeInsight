#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
typedef pair< int , int >PII;
// Order Statistic Tree

/* Special functions:

        find_by_order(k) --> returns iterator to the kth largest element counting from 0
        order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/

typedef tree<PII,null_type,less<PII>,rb_tree_tag,tree_order_statistics_node_update>
ordered_set;

typedef long long LL;
const int MAXN = 1e5+7;

int a[MAXN];
int cum[MAXN];
int n;

LL solve(int x) {
    LL ans = 0;
    ordered_set os;
    os.insert(PII(0, 0));
    for (int i = 1; i <= n; i++) {
        cum[i] = cum[i-1];
        if (a[i] <= x) cum[i]++;
        else cum[i]--;
        ans += os.order_of_key(PII(cum[i], 0));
        os.insert(PII(cum[i], i));
    }

//    cout << x << " -> " << ans << endl;
    return ans;
}


int main() {
    cin >> n;

    vector< int >v(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[i-1] = a[i];
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    LL k = n*1LL*(n+1);
    k /= 2;
    k = k/2+1;

//    cout << "need " << k << "-th" << endl;

    int lo = 0, hi = v.size()-1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (k <= solve(v[mid])) hi = mid-1;
        else lo = mid+1;
    }

    cout << v[lo] << endl;


    return 0;
}
