#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int A,B;
    cin >> A>>B;
    vec<string> c(100,string(100,'.'));
    rep(i,50) c[i] = string(100,'#');

    rep(i,A-1) c[(i/50)*2][(i%50)*2] = '.';
    rep(i,B-1) c[99-((i/50)*2)][(i%50)*2] = '#';
    
    cout << 100 << " " << 100 << endl;
    rep(i,100) cout << c[i] << endl;
}