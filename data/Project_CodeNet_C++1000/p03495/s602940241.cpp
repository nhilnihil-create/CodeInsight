#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int N,K;
    cin >> N >> K;
    map<int,int> m;
    REP(i,N){
        int a;
        cin >> a;
        m[a] += 1;
    }
    
    vector<int> v;
    for ( auto itr = m.begin(); itr != m.end(); ++itr){
        int val = itr->second;
        v.push_back(val);
    }
    
    sort(v.begin(),v.end());
    //for ( auto a: v) cout << a << endl;
    int ans = 0;
    if ( v.size() > K ){
        for ( int i = 0; i < v.size()-K; ++i){
            ans += v[i];
        }
    }
    cout << ans << endl;
    
    return 0;
}
