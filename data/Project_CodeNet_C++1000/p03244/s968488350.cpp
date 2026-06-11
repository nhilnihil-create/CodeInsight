#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    map<int, int> mEven, mOdd;
    for(int i = 0; i < n; i += 2) mEven[v[i]]++;
    for(int i = 1; i < n; i += 2) mOdd[v[i]]++;

    vector<pair<int, int>> evenCnt, oddCnt;
    for (auto mi = mEven.begin(); mi != mEven.end(); mi++){
        evenCnt.push_back(make_pair(mi->second, mi->first));
    }
    for (auto mi = mOdd.begin(); mi != mOdd.end(); mi++){
        oddCnt.push_back(make_pair(mi->second, mi->first));
    }

    int ans;
    sort(rall(evenCnt));
    sort(rall(oddCnt));
    if (evenCnt[0].first == oddCnt[0].first){
        if (evenCnt[0].second == oddCnt[0].second){
            if (evenCnt[1].first > oddCnt[1].first){
                ans = n - oddCnt[0].first - evenCnt[1].first;
            }
            else{
                ans = n - evenCnt[0].first - oddCnt[1].first;
            }
        }
        else{
            ans = n - evenCnt[0].first - oddCnt[0].first;
        }
    }
    else if (evenCnt[0].first > oddCnt[0].first){
        if (evenCnt[0].second == oddCnt[0].second){
            ans = n - evenCnt[0].first - oddCnt[1].first;
        }
        else{
            ans = n - evenCnt[0].first - oddCnt[0].first;
        }
    }
    else if (evenCnt[0].first < oddCnt[0].first){
        if (evenCnt[0].second == oddCnt[0].second){
            ans = n - oddCnt[0].first - evenCnt[1].first;
        }
        else{
            ans = n - oddCnt[0].first - evenCnt[0].first;
        }
    }
    cout << ans << endl;
    return 0;
}