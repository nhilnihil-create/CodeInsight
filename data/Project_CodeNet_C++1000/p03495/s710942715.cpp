//url:
//problem name: Brick Break

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N;
    int K;
    cin >> N >> K;
    map<int,int> mp;
    set<int> st;
    ll ans = 0;
    REP(i,N) {
        int a; cin >> a;
        st.insert(a);
        if(mp.count(a)) mp[a]++;
        else mp[a] = 1;
    }
    vector<P> res;
    for(P p:mp) res.push_back(make_pair(p.second,p.first));
    sort(res.begin(),res.end());
    if(st.size() <= K) {
        cout << 0 << endl;
        return 0;
    }
    else {
        REP(i,st.size()-K) {
            ans += res[i].first;
        }
    }
    cout << ans << endl;
}