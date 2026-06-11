#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
// #define DEBUG 10
 
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<ll, ll>;
 
const int oo = 1e9 + 7;
const ll mod = 1e9+7, maxn = (2 * 1e5) + 10 , maxm = (1 << 18);
const ld PI = acos(-1);
int parent[maxn];

void init(int n){
    for (int i=0; i<=n; i++) parent[i] = i;
}

int find(int x){
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void union_set(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a > b) swap(a, b);

    parent[b] = a;
}

int main (){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    set<int> ans;
    init(n);

    for (int i=0; i<m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        union_set(x, y);
    }

    for (int i=1; i<=n; i++){
        ans.insert(find(i));
    }

    cout << ans.size() << endl;
    return 0;
}