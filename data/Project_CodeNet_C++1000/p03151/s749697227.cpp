//Ruthless Coding 
#include <bits/stdc++.h>

#define uni(x)      (x).resize(unique(ALL(x)) - (x).begin())
#define fprint(v)   for(auto x : v) cout << x << ' '
#define ALL(x)      (x).begin(), (x).end()
#define PI          3.14159265358979323846
#define MP(x, y)    make_pair(x, y)
#define SZ(x)       int((x).size())
#define PB(x)       push_back(x)
#define ld          long double
#define ll          long long
#define S           second 
#define F           first
#define nl          '\n'

using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
mt19937_64 rnd;

const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto &x : a){
        cin >> x;
    }
    for(auto &x : b){
        cin >> x;
    }
    vector<pair<ll, int>> ok, nk;
    for(int i = 0; i < n; i++){
        if(a[i] >= b[i]){
            ok.PB(MP(a[i], i));
        }else{
            nk.PB(MP(a[i], i));
        }
    }
    ll ans = SZ(nk);
    if(SZ(nk) == 0){
        cout << 0;
        return 0;
    }
    sort(ALL(ok), [&](pair<ll, int> p1, pair<ll, int> p2){
        return abs(p1.F - b[p1.S]) > abs(p2.F - b[p2.S]);
    });
    sort(ALL(nk), [&](pair<ll, int> p1, pair<ll, int> p2){
        return abs(p1.F - b[p1.S]) < abs(p2.F - b[p2.S]);
    });
    ll sum = 0;
    for(auto &x : nk){
        ll extra = abs(x.F - b[x.S]);
        sum += extra;
    }
    ll csum = 0;
    int cnt = 0;
    for(auto &x : ok){
        csum += abs(x.F - b[x.S]);
        cnt++;
        if(csum >= sum){
            break;
        }
    }
    if(csum >= sum){
        cout << ans + cnt;
    }else{
        cout << -1;
    }
    return 0;
}
/*
    *** Most Impo.. -> check base case always
    1. Overflow Check (*, +)
    2. Index check (0 - based or 1 - based)
    3. Check for n = 1, 2, 3, 4....
    4. Corner Cases
*/