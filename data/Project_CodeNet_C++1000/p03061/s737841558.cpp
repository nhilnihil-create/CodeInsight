#include<iostream>
#include<vector>
#include<string>

using namespace std;
using ll = long long;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    ll n;
    std::cin >> n;
    std::vector<ll> a(n);
    std::vector<std::vector<std::pair<ll, ll>>> fact(n);

    std::cin >> a[0];
    ll g = a[0];
    for(int i = 1; i < n; i++){
        std::cin >> a[i];
        g = gcd(a[i], g);
    }

    // 1つ抜きの最大公約数の最大を求めれば良い
    // まず左からn個の最大公約数
    std::vector<ll> left(n);
    left[0] = a[0];
    for(int i = 1; i < n; i++){
        left[i] = gcd(left[i - 1], a[i]);
    }
    // 右からn個の最大公約数
    std::vector<ll> right(n);
    right[0] = a[n - 1];
    for(int i = 1; i < n; i++){
        right[i] = gcd(right[i - 1], a[n - i - 1]);
    }


    // 1つ抜きの最大公約数の最大値
    // 左端と右端は例外処理
    ll ans = left[n - 1]; // 1つも書き換えない場合
    ans = std::max(ans, left[n - 2]);
    ans = std::max(ans, right[n - 2]);
    for(int i = 1; i < n - 1; i++){
        // i個目を抜く
        ll tmp = gcd(left[i - 1], right[n - i - 2]);
        ans = std::max(ans, tmp);
    }

    std::cout << ans << std::endl;

    return 0;
}
