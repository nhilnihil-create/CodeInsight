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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        v.push_back({b,a});
    }
    int cnt = 1;
    int right = 0;
    sort(v.begin(), v.end());
    rep(i,m){
        if(i == 0) right = v[i].first;
        else{
            if(right <= v[i].second){
                cnt++;
                right = v[i].first;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}