#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N;
vector<ll> ls, rs;
ll lsum[100010], rsum[100010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i){
        int L, R;
        cin >> L >> R;
        ls.emplace_back(L);
        rs.emplace_back(R);
    }
    sort(ls.rbegin(), ls.rend());
    sort(rs.begin(), rs.end());
    for(int i = 0; i < N; i++){
        lsum[i] += ls[i];
        lsum[i + 1] += lsum[i];
        rsum[i] += rs[i];
        rsum[i + 1] += rsum[i];
    }
    ll res = 0;
    for(int i = 0; i < N; i++){
        chmax(res, lsum[i] - rsum[i]);
    }
    for(int i = 1; i < N; i++){
        chmax(res, lsum[i] - rsum[i - 1]);
        chmax(res, lsum[i - 1] - rsum[i]);
    }
    cout << res * 2 << endl;
    return 0;
}