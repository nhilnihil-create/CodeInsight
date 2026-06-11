#include<bits/stdc++.h>
#define SETPERCISION cout << fixed << setprecision(7)
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)


using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template<typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i: x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template<typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random_int(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
int range(int l, int r) { return l + rand() % (r - l + 1); }

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "DEBUG: [" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void init(int argc, char **argv) {
    IO;
    SETPERCISION;
    if (argc == 2 && !strcmp("input.txt", argv[1])) {
        cerr << "reading from in.txt" << endl;
        freopen(argv[1], "r", stdin);
    }
}
//#define int long long
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vpii vector<pair<int,int>>
#define vvpii vector<vector<pair<int,int>>>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vtiii vector<tuple<int,int,int>>
#define pii pair<int,int>
#define IINF 1e9
#define LINF 1e17
#define MOD ((int)1e9+7)
#define pb push_back
#define ppii pair<pair<int,int>,pair<int,int>>
#define f first
#define c second
#define priority_queue2(x...) priority_queue<x, vector<x>, greater<x>>
#define sz(x) ((int)x.size())
#define clr(x)  x.clear()

int n, K;
vector<int> a;
vector<vector<int>> dp;

int solve(int i, int remk) {
    if (i == n)
        if (remk == 0)return 1;
    return 0;

}
int main(int argc, char **argv) {
    init(argc, argv);
    cin >> n >> K;
    K++;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp.resize(n + 1, vector<int>(K + 1, 0));
    
    dp[n][1] = 1;
    for (int k = 2; k <= K; k++)
        dp[n][k] += dp[n][k - 1];
    for (int i = 0; i < n; i++)
        dp[i][1] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int k = 2; k <= K; k++) {
            vector<int> &next = dp[i + 1], &cur = dp[i];
            int mini = max(0, k - a[i] - 1);
            (cur[k] = next[k] - next[mini] + MOD) %= MOD;
            (cur[k] += cur[k - 1]) %= MOD;
        }
    }

    cout <<((dp[0][K] - dp[0][K - 1] + MOD) % MOD) << '\n';

    return 0;
}
