#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;
ll n ;
vector<ll> c(0);
vector<ll> mem;
vector<vector<ll>> place(200001,vector<ll>(0));

void prvec(vector<ll> vec){ //for debug
    ll n = vec.size();
    cout << "------------------------------------\n" ;
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
    cout << "------------------------------------\n" ;
}

void pr2d(vector<vector<ll>> vec){ // for debug
    ll h = vec.size();
    ll w = vec.at(0).size();
    cout << "------------------------------------\n" ;
    rep(i,h){
        rep(j,w){
            cout << vec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
    cout << "------------------------------------\n" ;
}

tuple<ll,ll,ll,ll,ll,ll> bamboocomb(ll x, vector<ll> length_list, ll number_of_bamboo){
    ll fa = 0,fb = 0,fc = 0;
    ll noca = -1, nocb = -1, nocc = -1;
    bitset<16> bx(x);
    for(ll i=0;i<number_of_bamboo;i++){
        if(bx.test(2*i)){
            if(bx.test(2*i+1)){
                fc += length_list.at(i);
                nocc++;
            }else{
                fa += length_list.at(i);
                noca++;
            }
        }else{
            if(bx.test(2*i+1)){
                fb += length_list.at(i);
                nocb++;
            }
        }
    }
    return make_tuple(fa,fb,fc,noca,nocb,nocc);
}

int main(){
    ll n,a,b,c; cin >> n >> a >> b >> c;
    vector<ll> l(n);
    rep(i,n) cin >> l.at(i);

    //採用しない->00,aの竹に採用->01,bの竹に採用->10,cの竹に採用->11

    ll ans = INF;

    for(ll i=0;i<(1<<(2*n));i++){
        tuple<ll,ll,ll,ll,ll,ll> candidate = bamboocomb(i,l,n);
        if(get<0>(candidate) * get<1>(candidate) * get<2>(candidate) == 0) continue;
        ans = min(ans,10*get<3>(candidate)+abs(get<0>(candidate) - a) + 10*get<4>(candidate)+abs(get<1>(candidate) - b) + 10*get<5>(candidate) + abs(get<2>(candidate) - c));
    }
    cout << ans << endl;
}