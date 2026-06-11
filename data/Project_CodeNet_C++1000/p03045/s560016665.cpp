#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

const int MAX_N = 100005;
int par[MAX_N];
int rn[MAX_N];

void init(int n){
    for(int i=0; i<n; i++){
        par[i] = i;
        rn[i] = 0;
    }
}

int find(int x){
    if(par[x] == x) {
        return x;
    } else{
        par[x] = find(par[x]);
        return par[x];
    }
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return;

    if(rn[x] < rn[y]){
        par[x] = y;
    } else{
        par[y] = x;
        if(rn[x] == rn[y]) rn[x]++;
    }
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main(){
    int N, M;
    cin >> N >> M;

    int X[M], Y[M], Z[M];
    for(int i=0; i<M; i++){
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--;Y[i]--;
    }

    init(N);

    for(int i=0; i<M; i++){
        unite(X[i], Y[i]);
    }

    map<int, int> m;
    int ans = 0;
    for(int i=0; i<N; i++){
        int root = find(i);
        if(m.count(root) == 0){
            ans++;
            m[root] = 1;
        }
    }

    cout << ans << endl;

    return 0;
}
