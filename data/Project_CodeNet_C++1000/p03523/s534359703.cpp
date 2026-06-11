#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    string s; cin >> s;
    vector<string> t;
    t.emplace_back("KIHBR");
    t.emplace_back("KIHBRA");
    t.emplace_back("KIHBAR");
    t.emplace_back("KIHBARA");
    t.emplace_back("KIHABR");
    t.emplace_back("KIHABRA");
    t.emplace_back("KIHABAR");
    t.emplace_back("KIHABARA");
    t.emplace_back("AKIHBR");
    t.emplace_back("AKIHBRA");
    t.emplace_back("AKIHBAR");
    t.emplace_back("AKIHBARA");
    t.emplace_back("AKIHABR");
    t.emplace_back("AKIHABRA");
    t.emplace_back("AKIHABAR");
    t.emplace_back("AKIHABARA");
    bool ans = false;
    for(auto &m: t) if(m == s) ans = true;
    ans ? YES() : NO();
}