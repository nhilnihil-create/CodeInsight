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
    queue<ll> qu;
    qu.emplace(3);
    qu.emplace(5);
    qu.emplace(7);
    ll count=0;
    while(1){
        ll x=qu.front();
        if(x>N)break;
        qu.pop();
        string S=to_string(x);
        ll n=S.size();
        ll a=0,b=0,c=0;
        for(auto p: S){
            if(p=='3')a++;
            else if(p=='5')b++;
            else if(p=='7')c++;
        }
        if(a&&b&&c)count++;
        qu.emplace(x*10+3);
        qu.emplace(x*10+5);
        qu.emplace(x*10+7);
    }
    print(count);
    return 0;
}