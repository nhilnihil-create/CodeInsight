#pragma target("avx")
#pragma target("O3")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using PP = std::pair<ll,P>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define rep(i,b,e) for(ll i=b; i<e; i++)
#define be(vec) vec.begin(),vec.end()
#define print(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");
#define scan(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
        int h, w;
        scanf("%d %d", &h, &w);
        std::vector<V> a(h+2, V(w+2, 1));
        rep(i, 1, h+1){
                char s[w+1];
                scanf("%s", s);
                rep(j, 1, w+1) a[i][j] = (s[j-1]=='#');
        }


        std::queue<PP> que;
        rep(i, 1, h+1) rep(j, 1, w+1) {
                if(a[i][j]){
                        rep(I, 0, 4){
                                que.emplace(1, P(i+dx[I], j+dy[I]));
                        }
                }
        }

        int ans = 0;
        while(!que.empty()){
                P p;
                int d;
                std::tie(d, p) = que.front();
                que.pop();
                if(a[p.fi][p.se]) continue;
                a[p.fi][p.se] = 1;
                ans = std::max(ans, d);
                rep(i, 0, 4){
                        int nx=p.fi+dx[i], ny=p.se+dy[i];
                        if(!a[nx][ny]) que.emplace(d+1, P(nx, ny));
                }
        }
        printf("%d\n", ans);
        return 0;
}