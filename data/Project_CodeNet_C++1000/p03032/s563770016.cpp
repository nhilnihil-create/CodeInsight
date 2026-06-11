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
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;++i){
        cin>>v[i];
    }

    ll ans = -INF;
    for(ll l=0;l<=n;++l){
        for(ll r=0;r<=n-l;++r){
            ll left = k - (l + r);
            if(left < 0)continue;

            vector<ll> a;
            for(ll i=0;i<l;++i){
                a.push_back(v[i]);
            }
            for(ll i=0;i<r;++i){
                a.push_back(v[n-i-1]);
            }
            sort(a.begin(), a.end());

            ll sum = 0;
            for(ll i=0;i<a.size();++i){
                sum += a[i];
            }

            for(ll i=0;i<min((ll)a.size(), left);++i){
                if(a[i] < 0){
                    sum -= a[i];
                }else{
                    break;
                }
            }
            ans = max(ans, sum);
        }
    }
    cout<<ans<<endl;

    return 0;
}