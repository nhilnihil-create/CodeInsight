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

struct F{
    ll o1;ll o2;ll o3;ll o4;
};

int main(){
    ll H;
    cin >> H;
    ll W;
    cin >> W;
    vector<vector<ll>> A(H, vector<ll>(W, 0));
    for(ll i=0;i<H;i++)
        for(ll j=0;j<W;j++)cin>>A[i][j];
    vector<F> ans(0);
    ll count=0;
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W-1;j++){
            if(A[i][j]%2){
                count++;
                A[i][j]--;
                A[i][j+1]++;
                ans.emplace_back(F{i,j,i,j+1});
            }
        }
        if(i!=H-1&&A[i][W-1]%2){
            count++;
            A[i][W-1]--;
            A[i+1][W-1]++;
            ans.emplace_back(F{i,W-1,i+1,W-1});
        }
    }
    print(count)
    for(auto p: ans)cout<<p.o1+1<<" "<<p.o2+1<<" "<<p.o3+1<<" "<<p.o4+1<<endl;
    return 0;
}