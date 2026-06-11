#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct edge{
    ll to, cost;
};


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

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n);
    for(ll i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(), a.end());

    vector<pair<ll, ll>> p(m);
    for(ll i=0;i<m;++i){
        ll b, c;
        cin>>b>>c;
        p[i] = make_pair(c, b);
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    ll count = 0;
    bool flag = false;
    vector<ll> q(n, 0);
    for(ll i=0;i<m;++i){
        if(flag){
            break;
        }
        for(ll j=0;j<p[i].second;++j){
            q[count] = p[i].first;
            count++;
            if(count == n){
                flag = true;
                break;
            }
        }
    }
    ll ans = 0;
    for(ll i=0;i<n;++i){
        ans += max(a[i], q[i]);
    }
    cout<<ans<<endl;

    return 0;
}