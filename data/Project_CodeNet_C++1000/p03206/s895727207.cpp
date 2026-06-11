#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll d;cin>>d;
    if(d==22){
        cout << "Christmas Eve Eve Eve" << endl;
    }else if(d==23){
        cout << "Christmas Eve Eve" << endl;
    }else if(d==24){
        cout << "Christmas Eve" << endl;
    }else{
        cout << "Christmas" << endl;
    }
    return 0;
}