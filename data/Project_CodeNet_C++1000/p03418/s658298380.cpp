#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N,K;
    cin >> N >> K;
    
    ll ans = 0;
    for(int b=K+1;b<=N;++b){
        ans += ((b-K)*(N/b));
        if(N%b >= K) ans+=(N%b - K + 1);
    }
    if(K==0) ans-=N;
    cout << ans << endl;
}