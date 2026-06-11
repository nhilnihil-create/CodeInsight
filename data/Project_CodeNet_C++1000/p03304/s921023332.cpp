#include <bits/stdc++.h>
using namespace std;
//using ll = long long;
 #define int long long

#define LOG(variable) cout << #variable":\t" << (variable) << endl
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cout << (i) << ":\t" << (container)[(i)] << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, r, n) for(int i = (n); i >= (r); --i) // from n to r
#define REPOBJ(itr, obj) for(auto itr = (obj).begin(); itr != (obj).end() ; ++itr)
#define REPROBJ(itr, obj) for(auto itr = (obj).rbegin(), e = (obj).rend(); itr != e; ++itr)
#define COUTB(x) cout << (x) << "\n"
#define COUTS(x) cout << (x) << " "
#define PB push_back
#define SORT(obj) sort((obj).begin(), (obj).end())
#define SORTR(obj) sort((obj).begin(), (obj).end(), greater<>())
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define PI (acos(-1))

int lcm(int, int);
map<int,int> GetPrimeFactors(int);
bool IsPrime(int);
int Factorial(int);
int npr (int, int);
int ncr (int, int);

/***** MAIN *****/
void Main() {
    int n, m, d;
    cin >> n >> m >> d;
    if(d) {
        cout << 2.0 * (n-d) / (n*n) * (m-1);
    } else {
        cout << double(m-1) / n;
    }

    cout << "\n";
}
/***** MAIN *****/

signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}

int lcm(int a, int b) { return a / __gcd(a,b) * b;}

map<int,int> GetPrimeFactors(int n) {
    map<int,int> mp;
    // dived by 2, 3, 5, ...
    for(int i=2; i*i<=n; i+=2) {
        if(i==4) i = 3;
        while(n%i == 0) {
            ++mp[i];
            n /= i;
        }
    }
    if(n!=1) ++mp[n];

    return mp;
}

bool IsPrime(int a) {
    if(a <= 1) return false;
    if(a == 2) return true;
    if(a%2 == 0) return false;
    for(int i = 3; i*i <= a; i+=2) {
        if(a%i==0) return false;
    }
    return true;
}

int Factorial(int n){
    int ans = 1;
    while(n > 1){
        ans *= n;
        --n;
    }
    return ans;
}

int npr(int n, int r) {
    return Factorial(n)/Factorial(n-r);
}

int ncr (int n, int r){
    return npr(n,r)/Factorial(r);
}
