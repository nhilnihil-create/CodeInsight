#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<string, P>> v(n);
    rep(i,n){
        cin >> v[i].first >> v[i].second.first;
        v[i].second.second = i+1;
    }
    sort(v.begin(), v.end());
    string s = v[0].first;
    vector<P> w;
    rep(i,n){
        if(s == v[i].first){
            w.push_back(P(v[i].second.first, v[i].second.second));
        }
        else{
            sort(w.rbegin(), w.rend());
            for(auto p : w) cout << p.second << endl;
            w.clear();
            w.push_back(P(v[i].second.first, v[i].second.second));
        }
        s = v[i].first;
    }
    sort(w.rbegin(), w.rend());
    for(auto p : w) cout << p.second << endl;
    return 0;
}
