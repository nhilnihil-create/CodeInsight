#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    map<int,int> mii1,mii2;
    rep(i,n){
        if(i%2 == 0) mii1[v[i]]++;
        else mii2[v[i]]++;
    }
    auto itr1 = mii1.begin();
    auto itr2 = mii2.begin();
    vector<pair<int,int>> v1,v2;
    for(auto u : mii1){
        v1.push_back({u.second,u.first});
    }
    for(auto u : mii2){
        v2.push_back({u.second,u.first});
    }
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    if(v1[0].second == v2[0].second){
        if(v1.size() == 1){
            if(v2.size() != 1)cout << n/2 - v2[1].first << endl;
            else cout << n/2 << endl;
            return 0;
        }
        if(v2.size() == 1){
            if(v1.size() != 1)cout << n/2 - v1[1].first << endl;
            else cout << n/2 << endl;
            return 0;
        }
        //cout << "yes" << endl;
        cout << min(n - v1[0].first - v2[1].first, n - v1[1].first - v2[0].first) << endl;
        return 0;
    }
    cout << n - v1[0].first - v2[0].first << endl;
    return 0;
}