#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t n;
    cin >> n;
    vi c(n-1), s(n-1), f(n-1);
    rep(i,n-1) cin >> c.at(i) >> s.at(i) >> f.at(i);
    // まずはn=0にいる場合を考える
    vi t(n,0);
    rep(j,n-1){
        for(int64_t i=j; i<n-1; i++){
            // cout << "j:" << j << " i:" << i << " t:" << t.at(j) << endl;
            if(s.at(i)>t.at(j)){
                t.at(j) = s.at(i);
            }else{
                int64_t remain = t.at(j)%f.at(i);
                if(remain!=0){
                    t.at(j) += f.at(i) - remain;
                }
            }
            t.at(j) += c.at(i);
        }
        cout << t.at(j) << endl;
    }
    cout << 0 << endl;
}