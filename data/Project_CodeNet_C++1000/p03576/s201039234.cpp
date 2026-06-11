#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    vec<ll> X(N),Y(N);
    vec<ll> x(N),y(N);
    for(int i=0;i<N;i++){
        cin >> X[i] >> Y[i];
        x[i] = X[i],y[i] = Y[i];
    }
    ll ans = 4e18;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(int a=0;a<N;a++) for(int b=a+1;b<N;b++){
        for(int c=0;c<N;c++) for(int d=c+1;d<N;d++){
            int cnt = 0;
            for(int i=0;i<N;i++) cnt += x[a]<=X[i] && X[i]<=x[b] && y[c]<=Y[i] && Y[i]<=y[d];
            if(cnt>=K) ans = min(ans,(x[b]-x[a])*(y[d]-y[c]));
        }
    }
    cout << ans << "\n";
}