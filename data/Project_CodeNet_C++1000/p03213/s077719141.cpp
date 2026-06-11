#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;
const int mod = 1e9+7;

//エラストテネスの篩
struct sieve_of_Eratosthenes {
    vector<bool> prime;
    sieve_of_Eratosthenes(int m) {init(m);}
    void init(int m) {
        prime.resize(m+1,true);
        prime[1] = false;
        for (int i = 2; i <= m; i++) {
            if (prime[i]) {
                for (int j = 2*i; j <= m; j += i) prime[j] = false;
            }
        }
    }
};

vint x;

int dfs(int n, int sum) {
    if (sum > 75) return 0;
    if (n == x.size()) {
        if (sum == 75) return 1;
        else return 0;
    }
    int res = 0;
    REP(i,x[n]+1) {
        res += dfs(n+1,sum*i);
    }
    return res;
}

int main() {
    int n; cin >> n;
    sieve_of_Eratosthenes se(n);
    for (int i = 2; i <= n; i++) {
        if (se.prime[i]) {
            int a = i;
            int sum = 0;
            while (a <= n) {
                sum += n/a;
                a *= i;
            }
            x.push_back(sum+1);
        }
    }
    cout << dfs(0,1) << endl;
}