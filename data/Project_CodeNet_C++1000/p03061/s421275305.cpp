#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
template <typename T> 
using lim = numeric_limits<T>;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

const int N = 1e5;
ll a[N];
ll myleft[N];
ll myright[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    myleft[0] = a[0];
    for (int i = 1; i < n; i++){
        myleft[i] = gcd(myleft[i-1], a[i]);
    }

    myright[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--){
        myright[i] = gcd(myright[i+1], a[i]);
    }

    ll ans = max(myleft[n-2], myright[1]);
    for (int i = 1; i < n-1; i++){
        ans = max(ans, gcd(myleft[i-1], myright[i+1]));
    }
    cout << ans << "\n";
}