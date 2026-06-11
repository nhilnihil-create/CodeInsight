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
    string S;
    cin >> S;
    ll x;
    cin >> x;
    ll y;
    cin >> y;
    S+='T';
    ll n=S.size();
    ll F=0;
    ll T=0;
    vector<ll> vecx(0);
    vector<ll> vecy(0);
    for(ll i=0;i<n;i++){
        if(S[i]=='F')F++;
        else {
            if(T%2)vecy.emplace_back(F);
            else vecx.emplace_back(F);
            T++;
            F=0;
        }
    }

    //dpx[i][j]はvecx[i-1]まででj-9000に到達できるか
    vector<vector<bool>> dpx(9000, vector<bool>(18000, 0));
    vector<vector<bool>> dpy(9000, vector<bool>(18000, 0));
    
    dpx[0][9000]=1;
    dpy[0][9000]=1;

    if(vecx.size())dpx[1][vecx[0]+9000]=1;
    if(vecy.size()){
    dpy[1][vecy[0]+9000]=1;
    dpy[1][-vecy[0]+9000]=1;}
    for(ll i=1;i<vecx.size();i++)
        for(ll j=0;j<18000;j++){
            if(dpx[i][j]){
                dpx[i+1][j+vecx[i]]=1;
                dpx[i+1][j-vecx[i]]=1;
            }
        }
    for(ll i=1;i<vecy.size();i++)
        for(ll j=0;j<18000;j++){
            if(dpy[i][j]){
                dpy[i+1][j+vecy[i]]=1;
                dpy[i+1][j-vecy[i]]=1;
            }
        }
    if(dpx[vecx.size()][x+9000]&&dpy[vecy.size()][y+9000]){
        cout<<"Yes"<<endl;return 0;
    }
    print("No")

    return 0;
}
