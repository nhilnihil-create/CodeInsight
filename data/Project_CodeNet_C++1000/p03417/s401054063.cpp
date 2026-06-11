#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
ll n,m;
cin >> n >> m;
if (n > m) swap(n, m);
if(n==1){
    if(m==1){
        cout << 1 << endl;
    }
    else{
        cout << m - 2 << endl;
    }
}
else
    cout << (n - 2) * (m - 2) << endl;
}