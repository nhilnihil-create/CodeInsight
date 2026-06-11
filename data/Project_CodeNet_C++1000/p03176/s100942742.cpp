///apigs property
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define F first
#define S second
#define pb push_back
#define vll vector< ll >
#define vi vector< int >
#define pll pair< ll , ll >
#define pi pair< int , int >
#define all(s) s.begin() , s.end()
#define md (s + e) / 2
using namespace std;
typedef long long ll;
ll q, tree[1000005], a[555555], k, l, m, n, o, p;
map < ll , ll > mp;
vll adj[555555];
const ll mod = 1e9+7;
void update(ll s , ll e , ll node , ll idx , ll val){
    if(idx > e || idx < s)return;
    if(s == e){
        tree[node] = val;
        return;
    }
    update(s , md , node * 2 , idx , val);
    update(md + 1 , e , node * 2 + 1 , idx , val);
    tree[node] = max(tree[node * 2] , tree[node * 2 + 1]);
}
ll query(ll s , ll e , ll node , ll idx){
    if(s > idx)return 0;
    if(e <= idx)return tree[node];
    return max(query(s , md , node * 2 , idx) , query(md + 1 , e , node * 2 + 1 , idx));
}
int main() {
    fast , cin >> n;
    for(ll i = 1 ; i <= n; i++){
        cin >> a[i];
    }
    for(ll i = 1 ; i <= n ; i++){
        cin >> o;
        l = query(1 , n , 1 , a[i]) + o;
        p = max(l , p);
        update(1 , n , 1 , a[i] , l);
    }
    cout << p;
}
