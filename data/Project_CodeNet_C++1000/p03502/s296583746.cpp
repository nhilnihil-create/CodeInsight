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
long long digitsum(long long n){
    long long result = 0;
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}
int main(){
ll n;
cin >> n;
cout << (!(n%digitsum(n)) ? "Yes" : "No") << endl;
}