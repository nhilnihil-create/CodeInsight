#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T>
T chmin(T &a, T b){
    if(a > b){
        a=b;
        return true;
    }
    return false;
}

template<typename T>
T chmax(T &a, T b){
    if(a < b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int n; cin >> n;
    vector<pii> red(n), blue(n);
    for(int i=0; i<n; i++){
        cin >> red[i].first >> red[i].second;
    }
    for(int i=0; i<n; i++){
        cin >> blue[i].first >> blue[i].second;
    }

    sort(all(red));
    reverse(all(red));
    int ans=0;
    vector<bool> used(n, 0);
    for(int i=0; i<n; i++){
        int a, b;
        pii cur={INF, 0};
        tie(a, b)=red[i];
        for(int j=0; j<n; j++){
            if(used[j]) continue;
            int c, d;
            tie(c, d)=blue[j];
            if(a < c && b < d && cur.first > d){
                cur.first=d;
                cur.second=j;
            }
        }
        if(cur.first == INF) continue;
        ans++;
        used[cur.second]=true;
    }
    cout << ans << endl;
    return 0;
}