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
ll num[MAX_N];
int N, M;

void init(int n){
    for(int i=0; i<n; i++){
        par[i] = i;
        rn[i] = 0;
        num[i] = 1;
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
    ll t = num[x] + num[y];
    num[x] = num[y] = t;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main(){
    cin >> N >> M;

    int A[M], B[M];
    for(int i=0; i<M; i++){
        cin >> A[i] >> B[i];
        A[i]--;B[i]--;
    }

    reverse(A, A+M);
    reverse(B, B+M);

    init(N);
    ll ans = (ll)N*(N-1)/2;
    vector<ll> l;
    for(int i=0; i<M; i++){
        l.push_back(ans);

        if(!same(A[i], B[i])){
            int ra = find(A[i]);
            int rb = find(B[i]);
            ans -= (ll)num[ra]*num[rb];
        }
        unite(A[i], B[i]);
    }

    reverse(l.begin(), l.end());
    for(ll e : l) cout << e << endl;

    return 0;
}
