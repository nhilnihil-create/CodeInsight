#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;


#define loop(i, n) for(int i = 0;i < int(n);i++)
#define rloop(i, n) for(int i = int(n);i >= 0;i--)
#define range(i, a, b) for(int i = int(a);i <= int(b);i++)
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1, v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1, v2, v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1, v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1, v2, v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define endl '\n'

typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

template<typename T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


const int N = 1e5 + 5;
int arr[N];
int acc[N];
int n;

bool valid(int val) {
    range(i, 1, n) {
        if (arr[i] < val)acc[i] = -1;
        else acc[i] = 1;
        acc[i] += acc[i - 1];
    }

    Tree<pii> X;
    X.insert({0, 0});
    ll res = 0;
    range(i, 1, n) {
        int cnt = X.order_of_key(mp(acc[i], n + n));
        res += cnt;
        X.insert(mp(acc[i], i));
    }

    //cout << val << " " << res  << " " << (res*2 >= 1LL * n * (n + 1) / 2) << endl;
    return (res * 2 >= 1LL * n * (n + 1) / 2);
}

int main() {

#ifndef ONLINE_JUDGE
//    freopen("in.in", "r", stdin);
    //freopen("out.in", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vi v(n);
    range(i, 1, n)cin >> arr[i], v[i - 1] = arr[i];
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());

    //loop(i,SZ(v))valid(v[i]);

    int s = 0, e = SZ(v) - 1;
    while (s < e) {
        int mid = s + (e - s + 1) / 2;
        if (valid(v[mid]))
            s = mid;
        else
            e = mid - 1;
    }

    cout << v[e] << endl;


    return 0;
}
