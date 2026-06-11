#include <bits/stdc++.h>
#define repr(i,from,to) for(int (i)=(from);(i)<(to);(i)++)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
#define vprint(x) for(auto a:(x)) cout << x << endl;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) { a = b; return true;}
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) { a = b; return true;}
    return false;
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<set<int>> nbs(n);
    rep(i,n-1) {
        int tmpa,tmpb;cin>>tmpa>>tmpb;
        tmpa--;tmpb--;
        nbs[tmpa].insert(tmpb);
        nbs[tmpb].insert(tmpa);
    }
    if(n==1){
        cout << "First" << endl;
        return 0;
    }
    function<pair<int,int>(int, int)> rec = [&] (int par, int now) {
        if(nbs[now].size()==1 && par != now) {return make_pair(0, now);}
        pair<int,int> res(-1,0);
        for(auto x: nbs[now]) {
            if(x == par) {continue;}
            auto tmp = rec(now, x);
            if(res.first < tmp.first) {
                res.first = tmp.first;
                res.second = tmp.second;
            }
        }
        res.first++;
        return res;
    };
    auto tmp = rec(0,0);
    DEBUG{
        printf("rec1 d:%d, cur:%d\n", tmp.first, tmp.second);
    }
    tmp = rec(tmp.second, tmp.second);
    DEBUG{
        printf("rec2 d:%d, cur:%d\n", tmp.first, tmp.second);
    }
    cout << (tmp.first %3 == 1 ? "Second" : "First") << endl;
    return 0;
}
