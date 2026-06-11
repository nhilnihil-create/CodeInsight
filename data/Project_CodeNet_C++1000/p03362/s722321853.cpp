#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P; 
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

vector<int> sieve_of_eratosthenes(){
    int MAX = 55556;
    vector<int> is_prime(MAX, 1);
    is_prime[0] = is_prime[1] = 0;
    for(int i=2; i<MAX; ++i){
        if(!is_prime[i]) continue;
        for(int j=i*2; j<MAX; j+=i) is_prime[j] = 0;
    }

    return is_prime;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> is_prime = sieve_of_eratosthenes();
    vector<int> primes;
    rep(i, 55556){
        if (is_prime[i]){
            if (i%5==1) primes.push_back(i);
        }
    }
    rep(i, n){
        cout << primes[i] << ' ';
    }
    cout << endl;

    return 0;
}