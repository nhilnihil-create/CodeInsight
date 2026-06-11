#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Z,W;
    cin >> N >> Z >> W;
    vec<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    if(N==1) cout << abs(A[0]-W) << "\n";
    else cout << max(abs(A[N-1]-W),abs(A[N-2]-A[N-1])) << "\n";
}