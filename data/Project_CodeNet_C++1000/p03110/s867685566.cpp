#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    vector<double> x(N,0);
    vector<string> u(N);
    for(ll i=0;i<N;i++)cin>>x[i]>>u[i];
    double sum=0;
    for(ll i=0;i<N;i++){
        if(u[i]=="JPY")sum+=x[i];
        else sum+=x[i]*380000;
    }

    cout << fixed << setprecision(10);
    print(sum)

    return 0;
}