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
    vector<ll> D(N,0);
    for(ll i=0;i<N;i++)cin>>D[i];
    Map H;
    H[0]++;
    for(ll i=0;i<N;i++){
        H[D[i]]++;
        //高橋君との時差ごとにカウント
        if(H[D[i]]==3||H[12]==2||H[0]==2){
            print(0);
            return 0;
        }
    }
    vector<ll> d(0);;
    for(auto p: H)for(ll i=0;i<p.second;i++)
    d.emplace_back(p.first);;
    ll n=d.size();
    ll ans=0;
    for(ll i=0;i<(1<<n);i++){
        ll ans2=INF;
        vector<ll> vec(0);
        vector<bool> check(24,0);
        ll next=-1;
        for(ll j=0;j<n;j++){
            if(i&(1<<j)){
                vec.emplace_back(d[j]);
                check[d[j]]=1;
            }
            else {
                if(j>0&&d[j]==d[j-1]&&!(i&(1<<(j-1)))){
                    next+=(1<<j);
                }
                vec.emplace_back(24-d[j]);check[24-d[j]]=1;
            }
        }
        for(ll j=0;j<n-1;j++)
            for(ll k=j+1;k<n;k++){
                ll f=abs(vec[j]-vec[k]);
                chmin(ans2,min(f,24-f));
            }
        chmax(ans,ans2);
        if(next>=0)
        i+=next;
    }
    print(ans)



    return 0;
}
