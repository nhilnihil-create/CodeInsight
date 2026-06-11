/*Allah Vorosha*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define n_p next_permutation
#define p_p prev_permutation
#define in insert
#define rev reverse
#define pf push_front
#define pob pop_back
#define uniq(v)         v.resize(distance(v.begin(),unique(v.begin(),v.end())))
#define all(x) (x).begin(),(x).end()
#define pof pop_front
#define ios ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define scn scanf
#define prt printf
#define rep(i, a, n) for(int i = a; i < n; i++)
#define mod 1000000007
#define yes cout << "YES\n"
#define no cout << "NO\n";
#define take for(auto &it : a) cin >> it;
#define out cout << a << "\n";
#define l_b lower_bound
#define u_b upper_bound
#define Max 100005
template<typename T> T mymax(T x, T y) {
    return (x > y ? x : y);
}

using namespace std;

const int N = 2e5 + 5;

ll lcm (ll c, ll d) {
    return (c * d) / (__gcd(c, d));
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), pre_gcd(n), suf_gcd(n);
    take;
    pre_gcd[0] = a[0];
    suf_gcd[n - 1] = a[n - 1];
    int ans = 0;
    for(int i = 1; i < n; i++) pre_gcd[i] = __gcd(a[i], pre_gcd[i - 1]);
    for(int i = n - 2; i >= 0; i--) suf_gcd[i] = __gcd(suf_gcd[i + 1], a[i]);
    for(int i = 0; i < n; i++) {
        if(i - 1 >= 0 && i + 1 < n) {
            ans = max(ans, __gcd(pre_gcd[i - 1], suf_gcd[i + 1]));
        }
        if(i == 0) {
            ans = max(ans, suf_gcd[i + 1]);
        }
        if(i + 1 == n) {
            ans = max(ans, pre_gcd[i - 1]);
        }
    }
    cout << ans << '\n';
}

int main() {

    solve();
    return 0;
}
