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
template <typename T>
inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>
inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    string s;cin>>s;
    bool yes=true;

    if(s[0]!='A') yes=false;

    ll cnt = 0;
    bool BIG=false;
    ll key=-1;
    for(ll i=2;i<=s.size()-2;i++){
        if(s[i]=='C'){
            cnt++;
            key=i;
        }
    }

    rep(i,s.size()){
        if(i==0 || i==key) continue;
        if(!('a'<=s[i] && s[i]<='z')) BIG=true;
    }

    if (cnt != 1)
        yes = false;
    if (BIG)
        yes = false;

    if(yes) cout<<"AC"<<endl;
    else cout<<"WA"<<endl;

    return 0;
}