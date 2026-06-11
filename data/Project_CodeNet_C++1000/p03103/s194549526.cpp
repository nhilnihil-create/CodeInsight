#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    int N,M;
    cin >> N >> M;
    vec<ll> A(N),B(N);
    for(int i=0;i<N;i++) cin >> A[i] >> B[i];
    vec<int> idx(N);
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](int i,int j){return A[i]<A[j];});
    ll ans = 0;
    for(auto i:idx){
        if(B[i]<M){
            ans += A[i]*B[i];
            M -= B[i];
        }else{
            ans += A[i]*M;
            M = 0;
        }
    }
    cout << ans << "\n";
}