#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;
vector<string> lis(0);

int digit(long long int n){
    string s;
    s = std::to_string(n);
    return s.size();
}

void dfs(ll a, ll d, string p){
    if(a == d){
        lis.emplace_back(p);
        return;
    }
    string l = p + '3';
    dfs(a+1, d, l);
    string m = p + '5';
    dfs(a+1, d, m);
    string n = p + '7';
    dfs(a+1, d, n);
}

int main(){
    ll N; cin >> N;
    ll ans = 0;
    ll d = digit(N);
    rep(i, 3, d){
        ans += pow(3, i) - 3*pow(2,i) + 3;
    }
    string p = "";
    dfs(0, d, p);
    for(auto k: lis){
        ll q = stoi(k);
        if(q > N){continue;}
        bool w = false, x = false, y = false;
        rep(j, 0, d){
            if(k[j] == '3'){w = true;}
            else if(k[j] == '5'){x = true;}
            else{y = true;}
        }
        if(x&&y&&w){ans++;}
    }
    prt(ans);
}