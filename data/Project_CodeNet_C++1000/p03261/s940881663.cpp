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
    ll n;cin>>n;
    bool yes=true,fi_st=true;
    char c;
    map<string,bool> check;
    rep(i,n){
        string s;cin>>s;
        if (check[s] == true){
            yes = false;
        }
        else{
            check[s] = true;
        }
        if(fi_st){
            fi_st=false;
            c=s[s.size()-1];
            continue;
        }

        if(c!=s[0]){
            yes=false;
        }else{
            c=s[s.size()-1];
        }
    }

    if(yes) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}