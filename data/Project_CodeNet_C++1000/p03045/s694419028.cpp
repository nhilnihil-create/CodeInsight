#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const ll oo = 1e18 + 7;
const ll mod = 1e9 + 7, maxn = (1e5) + 10;  
const long double PI = acos(-1);
int parent[maxn];

int find_parent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find_parent(parent[x]);
}

void union_set(int x, int y){
    x = find_parent(x);
    y = find_parent(y);

    if (x == y) return;

    parent[y] = x;
}

void init(){
    for (int i=0; i<maxn; i++) parent[i] = i;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    init();

    for (int i=0; i<m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        union_set(x, y);
    }

    set<int> ans;

    for (int i=1; i<=n; i++){
        ans.insert(find_parent(i));
    }

    cout << ans.size() << endl;
    return 0;
}