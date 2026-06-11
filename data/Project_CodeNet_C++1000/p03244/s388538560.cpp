//url:
//problem name: 

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
    cin >> N;
    veci V(N);
    set<int> odd;
    set<int> even;
    map<int,int> mp_odd;
    map<int,int> mp_even;
    REP(i,N) {
        cin >> V[i];
        if(i%2 == 0) {
            even.insert(V[i]);
            if(mp_even.count(V[i])) mp_even[V[i]]++;
            else mp_even[V[i]] = 1;
        }
        else {
            odd.insert(V[i]);
            if(mp_odd.count(V[i])) mp_odd[V[i]]++;
            else mp_odd[V[i]] = 1;
        }
    }

    vector<P> vec_even;
    vector<P> vec_odd;

    for(auto ret:mp_even) vec_even.push_back(P(ret.second,ret.first));
    for(auto ret:mp_odd) vec_odd.push_back(P(ret.second,ret.first));

    sort(vec_even.begin(),vec_even.end(),greater<P>());
    sort(vec_odd.begin(),vec_odd.end(),greater<P>());

    ll ans = 0;
    //cout << even.size() << " " << odd.size()<<endl;
    if(even.size() == 1 && odd.size() == 1) {
        for(int v: even) for(int w:odd) if(v == w) ans = N/2; else ans = 0;
    }
    if(even.size() == 1 && odd.size() > 1) {
        int v = vec_even[0].second;
        int w = vec_odd[0].second;
        if(v != w) ans = N/2-vec_odd[0].first;
        else ans = N/2 - vec_odd[1].first;
    } else if(even.size() > 1 && odd.size() == 1) {
        int v = vec_even[0].second;
        int w = vec_odd[0].second;
        if(v != w) ans = N/2-vec_even[0].first;
        else ans = N/2 - vec_even[1].first;
    } else if(even.size() > 1 && odd.size() > 1){
        int v = vec_even[0].second;
        int w = vec_odd[0].second;
        if(v != w) ans = N/2-vec_even[0].first + N/2-vec_odd[0].first;
        else ans = min(N-vec_even[0].first-vec_odd[1].first,N-vec_even[1].first-vec_odd[0].first);
    }

    cout << ans << endl;
}
