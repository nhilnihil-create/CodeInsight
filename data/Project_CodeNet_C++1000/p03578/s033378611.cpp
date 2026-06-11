#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll N, M;
    cin >> N;
    vector<ll> D(N);
    unordered_map<ll, ll> md;
    rep(i, N){
        cin >> D[i];
        if (md.find(D[i]) == md.end()){
            md[D[i]] = 1;
        }else{
            md[D[i]] += 1;
        }
    }
    cin >> M;
    vector<ll> T(M);
    unordered_map<ll, ll> mt;
    rep(i, M){
        cin >> T[i];
        if (mt.find(T[i]) == mt.end()){
            mt[T[i]] = 1;
        }else{
            mt[T[i]] += 1;
        }
    }

    if (N < M){
        puts("NO");
        return 0;
    }
    
    for(auto x: mt){
        if (md[x.first] < x.second){
            puts("NO");
            return 0;
        }
    }

    puts("YES");


    return 0;
}
