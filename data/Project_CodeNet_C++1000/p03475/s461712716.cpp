#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;
typedef pair<ll,ll> pairs;
typedef vector<pairs> p;


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

vector<vector<ll>> combination(ll n, ll r){
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
    for(ll i=0;i<v.size();++i){
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for(ll i=1;i<v.size();++i){
        for(ll j=0;j<i;++j){
            v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]);
        }
    }
    return v;
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
    ll n;
    cin>>n;
    ll c[n-1], s[n-1], f[n-1];
    for(ll i=0;i<n-1;++i){
        cin>>c[i]>>s[i]>>f[i];
    }

    for(ll i=0;i<n;++i){
        ll ans = 0;
        for(ll j=i;j<n-1;++j){
            if(ans < s[j]){
                ans = s[j];
            }else if(ans % f[j] != 0){
                ans += f[j] - ans % f[j];
            }
            ans += c[j];
        }
        cout<<ans<<endl;
    }

    return 0;
}