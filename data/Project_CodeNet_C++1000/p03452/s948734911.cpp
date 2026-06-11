#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<long long, long long>;

const string YES = "Yes";
const string NO = "No";
struct UnionFindPotential{
    vll parent;
    vll potential;
    vll rank;
    //* member functions
    UnionFindPotential(ll n){
        parent = vll(n);
        potential = vll(n, 0);
        rank = vll(n, 0);
        for(ll i=0; i< n; i++) parent[i] = i;
    }

    ll find(ll x){
        if(parent[x] == x) return x;
        else{
            ll r = find(parent[x]);
            potential[x] += potential[parent[x]];
            parent[x] = r;
            return r;
        }
    }

    ll get_potential(ll x){
        find(x);
        return potential[x];
    }

    void unite(ll x, ll y, ll d){ 
        //* potential(y)-potential(x) = d
        d += get_potential(x);
        d -= get_potential(y);
        x = find(x); y = find(y);
        if(x == y) return;
        if(rank[x] < rank[y]){
            parent[x] = y; //* new root is y
            potential[x] = -d;
        }
        else{
            if(rank[x] == rank[y]) rank[x]++;
            parent[y] = x;
            potential[y] = d;
        }
        return;
    }

    bool same(ll x, ll y){
        return find(x) == find(y);
    }
};
void solve(long long N, long long M, std::vector<long long> L, std::vector<long long> R, std::vector<long long> D){
    UnionFindPotential uf(N);
    bool isGood = true;
    for(ll i=0; i< M; i++){
        ll x = L[i]-1, y = R[i] -1, d = D[i];
        uf.unite(x, y, d);
        if(uf.get_potential(y)-uf.get_potential(x) != d){
            isGood = false;
            break;
        }
    }
    if(isGood) cout << YES << endl;
    else cout << NO << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> L(M);
    std::vector<long long> R(M);
    std::vector<long long> D(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&L[i]);
        scanf("%lld",&R[i]);
        scanf("%lld",&D[i]);
    }
    solve(N, M, std::move(L), std::move(R), std::move(D));
    return 0;
}
