#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<iomanip>

using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long

typedef pair<lint, lint> P;
bool cmpx(const P& l, const P& r){
    return (l.first < r.first);
}
bool cmpy(const P& l, const P& r){
    return (l.second < r.second);
}


int main(){
    int n, k; cin >> n >> k;
    vector<P> p;
    rep(i, n){
        lint x, y; cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    sort(all(p), cmpx);

    ulint ans = 1e9*1e10;
    rep(i, n - 1){
        vector<P> tmp; tmp.push_back(p[i]);
        for(int j = i + 1; j < n; j++){
            tmp.push_back(p[j]);
            if(tmp.size() < k) continue;
            sort(all(tmp), cmpy);
            ulint r = 1e10;
            rep(l, tmp.size() - k + 1){
                r = min(r, (ulint)(tmp[l+k-1].second - tmp[l].second));
            }
            ans = min(ans, r * (ulint)(p[j].first - p[i].first));
        }
    }

    cout << ans << endl;
}