#include <bits/stdc++.h>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define IMOD 1000000007 
#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define lrep(i,n) for(long long  i = 0; i < (long long)(n); i++)
#define lrep2(i,a,n) for(long long i = (long long)(a); i <= (long long)(n); i++)

#define irrep(i,n) for(int i = (int)(n); i > -1; i--)
#define irrep2(i,a,n) for(int i = (int)(n); i >= (int)(a); i--)

typedef long long ll;
typedef std::vector<char> v_char;
typedef std::vector<double> v_double;
typedef std::vector<std::vector<double> > v2_double;
typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<std::vector<std::string> > v2_string;
typedef std::vector<bool> v_bool;
typedef std::vector<std::vector<bool> > v2_bool;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std; 

void IsPrimeNum(ll n, v_bool &is_prime)
{
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i <= n; i++) {
        for(ll j = i*i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }
}

int main(void)
{
    int n;
    cin >> n;
    int n_max = 55555;

    v_bool is_prime(n_max+1, true);    
    IsPrimeNum(n_max, is_prime);
    v_int prime;

    int cnt = 0;
    irep(i, n_max) {
        if(is_prime[i] && i % 5 == 1) { prime.push_back(i); }
    }

    irep(i, n) {
        printf("%d ", prime[i]);
    }
    return 0;
}
/** atcoder **/
