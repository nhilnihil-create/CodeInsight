#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

int N, M;
vector<vector<P>> edge1(100001);
vector<vector<P>> edge2(100001);
bitset<100001> bit;
vector<ll> memo(100001, 0);

void rec(int corrent, int p = 0){
    
    if(bit[corrent]){
        if(memo[corrent] != p) { printf("No\n"); exit(0); }
        return;
    }
    bit[corrent] = true;
    memo[corrent] = p;

    for(auto e : edge1[corrent]) rec(e.first, p + e.second);
    for(auto e : edge2[corrent]) rec(e.first, p - e.second);
    
    return;
}

int main(void){
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        edge1[a].push_back(make_pair(b, c)), edge2[b].push_back(make_pair(a, c));
    }
    
    for(int i = 1; i <= N; ++i) if(!bit[i]) rec(i, 0);
    
    printf("Yes\n");
    
    return 0;
}
