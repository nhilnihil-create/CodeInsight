#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int A,B,C,X;
    cin >> A >> B >> C >> X;
    
    int ans = 0;
    rep(a,A+1)rep(b,B+1)rep(c,C+1){
        if(500*a+100*b+50*c==X) ++ans;
    }
    cout << ans << endl;
}