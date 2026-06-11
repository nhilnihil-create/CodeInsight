#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cerr<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> inline bool chmax(t&a,u b){if(a<b){a=b;return true;}return false;}
template<class t,class u> inline bool chmin(t&a,u b){if(b<a){a=b;return true;}return false;}

using Data = pair<ll, vi>;

int main(){
    vl n(3);
    int k;cin >> n[0] >> n[1] >> n[2] >> k;
    vector<vl> v(3);
    for(int i=0;i<3;++i){
        v[i].resize(n[i]);
        rep(j,n[i]) cin >> v[i][j];
        sort(v[i].rbegin(), v[i].rend());
    }
    priority_queue<Data> que;
    set<Data> se;
    que.push(Data(v[0][0] + v[1][0] + v[2][0], vi({0, 0, 0})));
    for(int i=0;i<k;++i){
        auto c = que.top();que.pop();
        cout << c.first << "\n";

        for(int j=0;j<3;++j){
            if(c.second[j]+1 < n[j]){
                ll sum = c.first - v[j][c.second[j]] + v[j][c.second[j]+1];
                auto num = c.second; num[j]++;
                auto d = Data(sum, num);
                if(!se.count(d)) se.insert(d), que.push(d);
            }
        }
    }
}