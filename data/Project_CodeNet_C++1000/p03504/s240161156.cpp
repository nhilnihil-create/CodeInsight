#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;


int main(){
    int N, C; cin >> N >> C;
    vector<int> s(N), t(N), c(N);
    rep(i,N) cin >> s[i] >> t[i] >> c[i];

    

    const int CHANNEL_NUM = 31;
    vector<vector<pair<int,int>>> a(CHANNEL_NUM);
    rep(i,N){
        a[c[i]].emplace_back(s[i],t[i]);
    }
    rep(i,CHANNEL_NUM){
        sort(a[i].begin(), a[i].end());
    }
/*
    rep(i,CHANNEL_NUM){
        cout <<  i << endl;
        for(auto tt: a[i]){
            cout << tt.first << " " << tt.second << endl;
        }
    }
*/
    vector<pair<int,int>> as;
    rep(i,CHANNEL_NUM){
        rep(j,a[i].size()){
            if(j == 0) as.push_back(a[i][j]);
            else{
                if (a[i][j-1].second == a[i][j].first){
                    //cout << i << " " << j << endl;
                    as.back().second = a[i][j].second;
                } 
                else{
                    as.push_back(a[i][j]);
                }
            }
        }
    }
/*
    rep(i,as.size()){
        cout << as[i].first << " " << as[i].second << endl;
    }
*/
    sort(as.begin(), as.end());

    vector<int> cum(100005,0);

    rep(i,as.size()){
        cum[as[i].first]++;
        cum[as[i].second+1]--;
    }

    rep(i,100004){
        cum[i+1] += cum[i];
    }

    int ans = 0;
    rep(i,100005){
        ans = max(ans,cum[i]);
    }

    cout << ans << endl;


} 