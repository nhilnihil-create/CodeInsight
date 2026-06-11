#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl
#define first(v) get<0>(v)
#define second(v) get<1>(v)
#define third(v) get<2>(v)
template <typename T> bool chmax(T &a, T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll L;
    cin >> L;
    L--;
    //T(from,to,cost)
    vector<T> ans(0);
    ll now=1;
    while(L>0){
        if(L%2){
            ans.emplace_back(T(now,now+1,0));
            ans.emplace_back(T(now,now+1,L/2+1));
            L/=2;
        }
        else{
            ans.emplace_back(T(now,now+1,0));
            ans.emplace_back(T(now,now+1,L/2));
            ans.emplace_back(T(now,INF,L));
            L/=2;L--;
        }
        now++;
    }
    ll d=ans.size();
    cout<<now<<" "<<d<<endl;
    for(ll i=0;i<d;i++){
        if(second(ans[i])!=INF){
            cout<<first(ans[i])<<" "<<second(ans[i])<<" "<<third(ans[i])<<endl;
        }
        else cout<<first(ans[i])<<" "<<now<<" "<<third(ans[i])<<endl;
    ;}


    return 0;
}
