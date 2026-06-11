#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int MOD = 1000000007;
typedef long long ll;

template<typename T> void print(const T & v);


int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> v(M);
    rep(i, M) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    int cnt = 0;
    int st = v[0].first, ed = v[0].second;
    for(int i = 1; i < M; i++){
        if(v[i].first < ed){
            st = max(st, v[i].first);
            ed = min(ed, v[i].second);
        }else{
            cnt++;
            st = v[i].first;
            ed = v[i].second;
        }
    }
    cnt++;
    cout << cnt << endl;
    return 0;
}


// Use For Debug
template <typename T>
void print(T const & v){
    for(int i = 0; i < v.size(); i++){
        if(i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}
