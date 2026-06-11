#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>>data(m);
    rep(i, 0, m){
        int p, y;
        cin >> p >> y;
        data[i] = make_tuple(p, y, i);
    }
    sort(data.begin(),data.end());
    vector<pii>ans(m);
    vector<int>town(n+1,0);
    rep(i, 0, m){
        int p, y, num;
        tie(p, y, num)= data[i];
        town[p]++;
        ans[num].first = p;
        ans[num].second = town[p];
    }
    rep(i, 0, m){
        cout << setw(6) << setfill('0') << ans[i].first;
        cout << setw(6) << setfill('0') << ans[i].second << endl;
    }
}