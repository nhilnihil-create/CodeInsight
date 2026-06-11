#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define to(k) E[k].to
#define next(k) E[k].next
#define fuck_it_up return !puts("-1")

using namespace std ;

typedef long long ll ;

const int N = 200010 ;

int n ;
ll minx ;
int cnt ;
int sz[N] ;
int fa[N] ;
ll dis[N] ;
int head[N] ;
struct tree{
    int id ;
    ll val ;
}base[N] ;
struct Edge{
    int to ;
    int next ;
}E[N * 2] ;
map <ll, int> s ;

bool comp(tree a, tree b){
    return a.val > b.val ;
}
void add(int u, int v){
    to(++ cnt) = v ;
    next(cnt) = head[u] ;
    head[u] = cnt ;
}
void dfs(int x){
    for (int k = head[x] ; k ; k = next(k))
        dis[to(k)] = dis[x] + n - 2 * sz[to(k)], dfs(to(k)) ;
}
int main(){
    cin >> n ;
    for (int i = 1 ; i <= n ; ++ i) sz[i] = 1 ;
    for (int i = 1 ; i <= n ; ++ i){
        scanf("%lld", &base[i].val) ;
        s[base[i].val] = base[i].id = i ;
    }
    sort(base + 1, base + n + 1, comp) ;
    for (int i = 1 ; i < n ; ++ i){
        int x = base[i].id ;
        ll y = base[i].val ;
        int delta = n - 2 * sz[x] ;
        if (delta <= 0) fuck_it_up ;
        if (!s.count(y - delta)) fuck_it_up ;
        fa[x] = s[y - delta] ; minx += sz[x] ;
        sz[fa[x]] += sz[x] ; add(fa[x], x) ;
    }
   // for (int i = 1 ; i <= n ; ++ i) cout << fa[i] << " " ;
    dis[base[n].id] = minx ; dfs(base[n].id) ;
    for (int i = 1 ; i <= n ; ++ i)
        if (dis[base[i].id] != base[i].val) fuck_it_up ;
    for (int i = 1 ; i < n ; ++ i)
        cout << base[i].id << " " << fa[base[i].id] << '\n';
}
