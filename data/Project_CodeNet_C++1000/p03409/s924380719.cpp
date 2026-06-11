#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<long long,int> P;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> r(n), b(n);

    rep(i, n){
        int x, y;
        cin >> x >> y;
        r[i] = make_pair(y, x);
    }
    rep(i, n){
        int x, y;
        cin >> x >> y;
        b[i] = make_pair(x, y);
    }

    sort(r.begin(), r.end());
    sort(b.begin(), b.end());

    int cnt = 0;
    bool used[n];
    rep(i, n) used[i] = false;

    rep(i, n){
        rrep(j, n){
            if(!used[j] && b[i].first > r[j].second && b[i].second > r[j].first){
                used[j] = true;
                cnt ++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}