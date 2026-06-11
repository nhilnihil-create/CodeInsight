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




int main() {


    ll n,m; cin >> n >> m;
    ll p = 1;
    vector<pair<pair<ll,ll>,pair<ll,string>>> v(m);

    rep(i,m){
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second.first = i;
    }

    sort(v.begin(),v.end());

    rep(i,m){
        if(i == 0) p = 1;
        else {
            if(v[i].first.first == v[i-1].first.first) p ++;
            else p = 1;
        }
        ostringstream sout1,sout2;
        sout1 << setfill('0') << setw(6) << v[i].first.first;
        sout2 << setfill('0') << setw(6) << p;
        string s1 = sout1.str();
        string s2 = sout2.str();

        v[i].second.second = s1+s2;
    }

    rep(i,m){
        v[i].first.first = v[i].second.first;
    }

    sort(v.begin(),v.end());

    rep(i,m){
        cout << v[i].second.second << endl;
    }


    return 0;
}
