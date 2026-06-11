#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int ans;

struct UnionFind{
    vector<int> par;
    
    UnionFind(int N) : par(N) {
        for (int i = 0; i < N; i++) {
            par[i] = i;
        }
    }

    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);

        if(rx == ry) return;
        par[rx] = ry;
        ans++;
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    int x, y, z;
    ans = 0;
    UnionFind G(N);
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        x--;
        y--;
        G.unite(x, y);
    }
    printf("%d\n", N-ans);

}