#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;

// #define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll mod = (1000000007LL);

inline ll poww(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if(b & 1) res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}
inline pii operator+(pii A, pii B){
	return pii(A.f + B.f, A.s + B.s);
}
inline pii operator-(pii A, pii B){
	return pii(A.f - B.f, A.s - B.s);
}
inline ll mult(ll a, ll b){
	return (a * b) % mod;
}

ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

/*
	>Colocar (>DEFINE INT LONG LONG<) no inicio do template
	>mod = (1e9 + 7), por padrao (NAO ESQUECER DE ALTERAR)
	>NAO ESQUECER DEFINE INT LONG LONG
	> N = 1 ? 
*/

///CUIDADO COM MAXN
#define N 300050

int n, m, q, k, v[N], ans;

pii TT, w[N];

string s;
vector<int> caras;
int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0);
    cin>>s;
    n = sz(s);
    for(int i = 0; i < n; i++){
        if(s[i] == '1') caras.pb(i+1);
    }
    if(s[0] != '1'){
        cout<<"-1\n";
        return 0;
    }
    for(auto i: caras){
        if(!binary_search(all(caras), n-i)){
            cout<<"-1\n";
            return 0;
        }
    }
    vector<vector<int> > grafo;
    grafo.resize(n+1);
    int cnt = 1;
    for(int i = 1; i <= sz(caras); i++){
        grafo[cnt].pb(cnt + 1);
        grafo[cnt + 1].pb(cnt);
        ++cnt;
    }
    cnt++;
    int curr = 0;
    for(int i = 1, j = 0; j < sz(caras); j++,i++){
        curr ++;
        // cout<<i<<" "<<caras[j]<<" "<<curr<<"\n";
        while(curr != caras[j]){
            grafo[i].pb(cnt);
            grafo[cnt].pb(i);
            ++cnt;
            curr ++;
        }
    }
    // cout<<"\n";
    for(int i = 1; i <= n; i++){
        for(auto u: grafo[i]){
            if(i<u)
            cout<<i<<" "<<u<<"\n";
        }
    }
}