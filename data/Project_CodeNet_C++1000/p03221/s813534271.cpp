#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct Edge{
    ll to, weight;
    Edge(ll t, ll w) : to(t), weight(w){}
};
using graph = vector<vector<ll>>;
using Graph = vector<vector<Edge>>;


ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

// 回文
bool kai(string S){
    bool flag = true;
    for(ll i=0;i<S.size()/2;++i){
        if(S[i] != S[S.size()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
// ---------------------------------------------

string solve(ll x){
    string sx = to_string(x);
    string re = "";
    for(ll i=0;i<6-sx.size();++i){
        re += "0";
    }
    re += sx;
    return re;
    //return to_string(x);
}

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> p(m), y(m);
    vector<ll> c[n];
    for(ll i=0;i<m;++i){
        cin>>p[i]>>y[i];
        p[i]--;
        c[p[i]].push_back(y[i]);
    }

    for(ll i=0;i<n;++i){
        sort(c[i].begin(), c[i].end());
    }
    for(ll i=0;i<m;++i){
        string fir = solve(p[i]+1);
        ll flag = lower_bound(c[p[i]].begin(), c[p[i]].end(), y[i]) - c[p[i]].begin() + 1;
        string sec = solve(flag);
        string ans = fir + sec;
        cout<<ans<<endl;
    }

    //cout<<"check"<<endl;

    return 0;
}