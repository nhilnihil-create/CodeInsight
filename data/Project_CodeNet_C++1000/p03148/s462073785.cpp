#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N, K; cin >> N >> K;
    vector<ll> t(N), d(N);
    for (ll i = 0; i < N; i++) {
        cin >> t[i] >> d[i];
    }
    
    vector<llll> di(N);
    for (ll i = 0; i < N; i++) {
        di[i] = make_pair(d[i], i);
    }

    sort(ALL(di), greater<llll> ());
    ll tmp, ans; ans = 0;
    for (ll i = 0; i < K; i++) {
        ans += di[i].first;
    }
    set<ll> S, Si;
    for (ll i = 0; i < K; i++) {
        S.insert(t[di[i].second]);
        Si.insert(di[i].second);
    }
    ll x = S.size();
    ans = ans + x * x;

    map<ll, ll> m;
    priority_queue<ll> p;
    for (ll i = 0; i < N; i++) {
        if(!S.count(t[i])){
            if(m.count(t[i])){
                m[t[i]] = max(d[i], m[t[i]]);
            }
            else{
                m[t[i]] = d[i];
            }
        }
    }
    for (auto v : m){
        p.push(v.second);
    }

    map<ll, llll> mm;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (ll i = 0; i < N; i++) {
        if(S.count(t[i])){
            if(mm.count(t[i])){
                mm[t[i]] = max(make_pair(d[i], i), mm[t[i]]);
            }
            else{
                mm[t[i]] = make_pair(d[i], i);
            }
        }
    }
    for (ll i = 0; i < N; i++) {
        if(S.count(t[i])){
            if(mm[t[i]].second != i && Si.count(i)){
                q.push(d[i]);
            }
        }
    }

    tmp = ans;
    while(!p.empty() && !q.empty()){
        ll v = p.top(); p.pop();
        ll w = q.top(); q.pop();
        tmp += v; tmp -= w;
        tmp -= x*x; x++;
        tmp += x*x;
        ans = max(tmp, ans);
    }

    printf("%lld\n", ans);

}