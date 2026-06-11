#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

const int maxv = 100005;

int main(){
    int N, C; cin >> N >> C;
    vector<vector<pair<int, int>>> st(31, vector<pair<int, int>>());
    rep(i,N){
        int s, t, c; cin >> s >> t >> c;
        st[c].emplace_back(s, t);
    }

    rep(i,31){
        sort(st[i].begin(), st[i].end());
    }

    vector<vector<pair<int,int>>> st2(31, vector<pair<int, int>>());
    
    rep(i,31){
        rep(j,st[i].size()){
            if (j == 0) st2[i].emplace_back(st[i][j].first, st[i][j].second);
            else{
                if(st[i][j-1].second != st[i][j].first){
                    st2[i].emplace_back(st[i][j].first, st[i][j].second);
                }else{
                    st2[i].back().second = st[i][j].second;
                }
            }
        }
    }


    vector<int> cum(maxv+1,0);
    rep(i,31){
        rep(j,st2[i].size()){
            cum[st2[i][j].first]++;
            cum[++st2[i][j].second]--;
        }
    }

/*
    rep(i,N){
        cum[s[i]]++;
        cum[t[i]]--;
    }
*/

    int ans = 0;
    rep(i,maxv){
        cum[i+1] += cum[i];
        ans = max(ans, cum[i+1]);
    }

    cout << ans << endl;


}