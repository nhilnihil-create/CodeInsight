#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
#define coutd(i) cout << std::fixed << std::setprecision(i)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Set = std::set<T>;
template<class T, class U>
using Map = std::map<T, U>;

template<class T>
using Graph = vector<vector<T>>;

const int INT_BIG = 1<<28;

int main() {
    int N;
    cin >> N;
    vll As(N);
    vll Bs(N);
    ll asum = 0;
    ll bsum = 0;
    rep(i, N) {
        cin >> As[i];
        asum += As[i];
    }
    rep(i, N) {
        cin >> Bs[i];
        bsum += Bs[i];
    }

    ll count = 0;
    rep(i, N) {
        if (As[i] < Bs[i]) count += std::ceil((Bs[i] - As[i])/2.0);
    }
    cout << ((count <= bsum - asum) ? "Yes" : "No") << endl;
}