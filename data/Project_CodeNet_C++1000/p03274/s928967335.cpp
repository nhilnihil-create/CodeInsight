#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    vec<int> X(N);
    for(auto& x:X) cin >> x;
    int ans = 2e9;
    for(int i=0;i+K<=N;i++){
        int l = i,r = i+K-1;
        if(X[l]<=0 && X[r]<=0) ans = min(ans,abs(X[l]));
        else if(X[l]>=0 && X[r]>=0) ans = min(ans,abs(X[r]));
        else ans = min(ans,min(2*abs(X[l])+abs(X[r]),abs(X[l])+2*abs(X[r])));
    }
    cout << ans << "\n";
}