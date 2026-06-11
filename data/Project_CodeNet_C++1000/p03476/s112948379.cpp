#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MAX_N = 1000000; 

vector<int> prime(MAX_N);
vector<bool> is_prime(MAX_N+1);
vector<int> ans_vec(MAX_N+1, 0);

// n以下の素数を返す
void sieve(int n){
    int p = 0;
    rep(i, n+1) is_prime.at(i) = true;
    is_prime.at(0) = is_prime.at(1) = false;
    rep2(i, 2, n+1){
        if(is_prime.at(i)){
            prime.at(++p) = i;
            for (int j = 2*i; j <= n; j+= i) is_prime.at(j) = false;
        }
    }
    return;
}

int main(){
    int q, l, r_max=0, ans = 0;
    cin >> q;
    vector<int> left(q), right(q);
    rep(i, q){
        cin >> left.at(i) >> right.at(i);
        chmax(r_max, right.at(i));
    }
    sieve(1000000);
    rep2(i, 2, r_max+1){
        if(is_prime.at(i) && is_prime.at((i+1)/2)) {
            ans_vec.at(i) = ans_vec.at(i-1) + 1;
        }
        else ans_vec.at(i) = ans_vec.at(i-1);
    }
    rep(i, q){
        cout << ans_vec.at(right.at(i)) - ans_vec.at(left.at(i)-1) << endl;
    }
}