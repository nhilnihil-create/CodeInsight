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
vector<pll> ls, rs;
bool used[100010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i){
        int L, R;
        cin >> L >> R;
        ls.push_back({L, i});
        rs.push_back({R, i});
    }
    sort(ls.rbegin(), ls.rend());
    sort(rs.begin(), rs.end());

    int cnt = 0;
    int l = 0, r = 0;
    ll x = 0;
    ll res = 0;
    while(cnt < N){
        cnt++;
        bool flag = false;
        if(cnt % 2){
            while(l < N){
                if(used[ls[l].second]) l++;
                else break;
            }
            if(N == l || ls[l].first < x) flag = true;
            else{
                used[ls[l].second] = true;
                res += ls[l].first - x;
                x = ls[l].first;
            }
        }else{
            while(r < N){
                if(used[rs[r].second]) r++;
                else break;
            }
            if(N == r || rs[r].first > x) flag = true;
            else{
                used[rs[r].second] = true;
                res += x - rs[r].first;
                x = rs[r].first;
            }
        }
        if(flag) break;
    }
    ll ans = res + abs(x);
    memset(used, 0, sizeof(used));
    l = 0, r = 0;
    x = 0;
    res = 0;
    cnt = 1;
    while(cnt <= N){
        cnt++;
        bool flag = false;
        if(cnt % 2){
            while(l < N){
                if(used[ls[l].second]) l++;
                else break;
            }
            if(N == l || ls[l].first < x) flag = true;
            else{
                used[ls[l].second] = true;
                res += ls[l].first - x;
                x = ls[l].first;
            }
        }else{
            while(r < N){
                if(used[rs[r].second]) r++;
                else break;
            }
            if(N == r || rs[r].first > x) flag = true;
            else{
                used[rs[r].second] = true;
                res += x - rs[r].first;
                x = rs[r].first;
            }
        }
        if(flag) break;
    }
    cout << max(res + abs(x), ans) << endl;
    return 0;
}