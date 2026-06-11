#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int A,B,C,K;
    cin >> A >> B >> C >> K;
    ll ans = max({A,B,C});
    rep(i,K) ans *= 2;
    
    cout << A+B+C+ans - max({A,B,C})<< endl;
}
