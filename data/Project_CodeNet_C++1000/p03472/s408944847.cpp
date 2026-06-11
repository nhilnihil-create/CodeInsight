#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

vector<ll> m(1001,0);

int main(){

    ll n,h,a,b,ans = 0; cin >> n >> h;
    vector<pair<ll,char>> v(2*n+1,make_pair(-1,'a'));

    rep(i,n){
        cin >> a >> b;

        v[i].first = a;
        v[i].second = 'a';

        v[i+n].first = b;
        v[i+n].second = 'b';
    }

    sort(v.begin(),v.end());

    for(int i = v.size()-1; i >= 0; i --){
        //cout << v[i].second << " " << v[i].first<< endl;
        if(v[i].second == 'b'){
            ans ++;
            h -= v[i].first;
        }else{
            ans += (h/v[i].first) + ((h%v[i].first == 0)?0:1);
            break;
        }
        if(h <= 0) break;
    }

    cout << ans;


    return 0;
}