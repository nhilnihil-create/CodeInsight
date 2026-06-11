//thx to drken!
//http://drken1215.hatenablog.com/entry/2018/12/16/024400

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
 
// #include <iostream> // cout, endl, cin
// #include <string> // string, to_string, stoi
// #include <vector> // vector
// #include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
// #include <utility> // pair, make_pair
// #include <tuple> // tuple, make_tuple
// #include <cstdint> // int64_t, int*_t
// #include <cstdio> // printf
// #include <map> // map
// #include <queue> // queue, priority_queue
// #include <set> // set
// #include <stack> // stack
// #include <deque> // deque
// #include <unordered_map> // unordered_map
// #include <unordered_set> // unordered_set
// #include <bitset> // bitset
// #include <climits>
// #include <cmath>
// #include <iomanip>
// #include <functional>
// #include <numeric>
// #include <random>
 
using namespace std;
    
#define int long long
#define pb push_back
#define eb emplace_back
// #define F first
// #define S second-l
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define rep(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define ve vector
#define vi vector<int>
#define vp vector<pair<int,int>>
#define vvi vector<vector<int>>
#define UNIQUE(a) sort(all(a)), a.erase(unique(all(a)), a.end())
 
template<typename T> using pq = priority_queue<T,vector<T>,greater<T>>; 
using ll = long long;
ll INF = LLONG_MAX / 10 - 100;
ll mod = 1e9 + 7;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
vector<ll> prime;

long double pi = 3.141592653589793238;
    
class fact {
public:
    int fmod = 1e9+7;
    vector<int> fac, finv, inv;
    fact (int n, int Mod = 1e9+7) {
        fmod = Mod;
        fac = vector<int>(n + 1, 0);
        finv = vector<int>(n + 1, 0);
        inv = vector<int>(n + 1, 0);
        fac[0] = 1; for (int i = 1; i < n + 1; i++) fac[i] = fac[i-1] * i % fmod;
        for (int i = 0;i < n + 1;i++) finv[i] = fact::POW(fac[i], fmod-2);
        for (int i = 0;i < n + 1;i++) inv[i] = POW(i, fmod-2);
    }
    ll nCr(ll n, ll r) {if(n < r) return 0; return (fac[n] * finv[r] % fmod) * finv[n-r] % fmod;}
    ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%fmod;}a = a * a%fmod; b >>= 1;}return c;}
    inline int operator [] (int i) {return fac[i];}
};
    
void DEBUG(vector<int> a) {for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;}
void EMP(int x) {cout<<"!!!"<<x<<"!!!"<<endl;}
ll GCD(ll a, ll b) {ll c; while (b != 0) {c = a % b; a = b; b = c;}return a;}
ll LCM(ll a, ll b) {return (a / GCD(a, b)) * (b / GCD(a, b)) * GCD(a, b);}
ll POW(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = a * c%mod;}a = a * a%mod; b >>= 1;}return c;}
void PRI(ll n) {bool a[n + 1LL]; for (int i = 0; i < n + 1LL; i++) {a[i] = 1LL;}for (int i = 2; i < n + 1LL; i++) {if (a[i]) {prime.pb(i); ll b = i; while (b <= n) {a[b] = 0; b += i;}}}}
template <typename T> T chmin(T& a, T b) {if(a>b)a=b;return a;}
template <typename T> T chmax(T& a, T b) {if(a<b)a=b;return b;}
bool isSqrt(ll a) {return pow(sqrt(a),2) == a ? 1 : 0;}
void YesNo(bool a) {if (a) cout << "Yes"; else cout << "No"; cout << endl;}
void yesno(bool a) {if (a) cout << "yes"; else cout << "no"; cout << endl;}
void YESNO(bool a) {if (a) cout << "YES"; else cout << "NO"; cout << endl;}
double dis(int x1, int x2, int y1, int y2) {
    return sqrt((double)abs(x1-x2)*(double)abs(x1-x2)+(double)abs(y1-y2)*(double)abs(y1-y2));
}
int ceili(int x, int y) {
    if (x % y == 0) return x / y;
    else return x / y + 1;
}

// ll POW2(ll a, ll b) {ll c = 1; while (b > 0) {if (b & 1) {c = mul(a, c, mod);}a = mul(a, a, mod)%mod; b >>= 1;}return c;}

using pll = pair<ll, ll>;
void normalize(vector<pll> &nums) {
    if (nums.size() > 1) {
        if (nums[nums.size()-1].first == nums[nums.size()-2].first) {
            nums[nums.size()-2].second += nums[nums.size()-1].second;
            nums.pop_back();
        }
    }
}

void add(vector<pll> &nums) {
    if (nums.back().second == 1) {
        nums.back().first += 1;
    } else {
        nums.back().second--;
        nums.push_back({nums.back().first+1, 1});
    }
    normalize(nums);
}

void solve() {
    int n; cin >> n;
    vector<int> A(n); rep (i, n) cin >> A[i];
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector<pll> nums;
        nums.push_back({0, A[0]});
        bool ok = true;
        FOR (i, 1, n) {
            if (A[i-1] < A[i]) nums.push_back({0, A[i] - A[i-1]});
            else {
                int sum = 0;
                while (nums.size() > 0 && sum + nums.back().second <= A[i-1] - A[i]) {
                    sum += nums.back().second;
                    nums.pop_back();
                }
                nums.back().second -= A[i-1] - A[i] - sum;

                if (nums.back().first == mid - 1) {
                    if (nums.size() == 1) {
                        ok = false;
                        break;
                    }
                    int num = nums.back().second;
                    nums.pop_back();
                    add(nums);
                    nums.push_back({0, num});
                } else {
                    add(nums);
                }
            }
        }

        if (ok) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
 
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
