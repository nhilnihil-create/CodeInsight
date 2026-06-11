#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

using P = pair<ll,int>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    vec<ll> A(N);
    for(auto& x:A) cin >> x;
    sort(A.begin(),A.end());
    vec<P> Q(M);
    for(auto& p:Q) cin >> p.second >> p.first;
    sort(Q.rbegin(),Q.rend());
    ll ans = 0;
    int id = 0;
    for(int i=0;i<N;i++){
        if(id==M) ans += A[i];
        else if(Q[id].first>A[i]){
            ans += Q[id].first;
            Q[id].second--;
            if(!Q[id].second) id++;
        }else ans += A[i];
    }
    cout << ans << "\n";
}