#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9 + 7;
const int INF = 9e18;

vector< bool > prime_table(int n) {
    vector< bool > prime(n + 1, true);
    if(n >= 0) prime[0] = false;
    if(n >= 1) prime[1] = false;
    for(int i = 2; i * i <= n; i++) {
        if(!prime[i]) continue;
        for(int j = i + i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}


signed main() {
    auto prime = prime_table(100000);
    vector<int> ans;
    for (int i = 5; i * 2 + 1 <= 55555; i+= 5) {
        if (prime[i * 2 + 1]) ans.push_back(i * 2 + 1);
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cout << ans[i] << (i == N - 1 ? '\n' : ' ');
    }
}
