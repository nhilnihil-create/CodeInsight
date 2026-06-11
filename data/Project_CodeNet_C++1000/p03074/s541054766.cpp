#pragma target("avx")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
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
        int n, k;
        scanf("%d %d", &n, &k);
        getchar();
        char prev = '1';
        int cnt = 0;
        V a;
        rep(i, 0, n){
                char c = getchar();
                if(prev==c) cnt++;
                else {
                        a.push_back(cnt);
                        cnt = 1;
                }
                prev = c;
        }
        a.push_back(cnt);
        if(prev=='0') a.push_back(0);

        if(a.size()<k*2+1){
                ll ans = 0;
                for(ll x: a) ans += x;
                printf("%ld\n", ans);
                return 0;
        }

        ll ans = 0;
        rep(i, 0, a.size()-k*2){
                ll tmp = 0;
                rep(j, i, i+k*2+1){
                        tmp += a[j];
                }
                ans = std::max(ans, tmp);
                i++;
        }
        printf("%ld\n", ans);
        return 0;
}