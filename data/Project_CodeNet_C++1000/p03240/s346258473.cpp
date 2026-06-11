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

int main(){
    ll n;
    cin>>n;
    vector<ll> x(n), y(n), h(n);
    ll u;
    for(ll i=0;i<n;++i){
        cin>>x[i]>>y[i]>>h[i];
        if(h[i] != 0){
            u = i;
        }
    }

    for(ll i=0;i<=100;++i){
        for(ll j=0;j<=100;++j){
            bool flag = true;
            ll H = abs(x[u] - i) + abs(y[u] - j) + h[u];
            for(ll k=0;k<n;++k){
                if(h[k] == 0){
                    if(H > abs(x[k] - i) + abs(y[k] - j)){
                        flag = false;
                        break;
                    }
                }else if(H != abs(x[k] - i) + abs(y[k] - j) + h[k]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                cout<<i<<' '<<j<<' '<<H<<endl;
                return 0;
            }
        }
    }

    return 0;
}