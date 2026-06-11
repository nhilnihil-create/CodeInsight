#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> b(n);
    rep(i,n){
        cin >> b[i];
    }
    vector<int> ans;
    auto c = b;
    for(int i = 0;i < n;++i){
        for(int j = n;j > 0;--j){
            if(b.empty()) break;
            if(b.size() < j) continue;
            if(b[j-1] == j) {
                ans.push_back(j);
                b.erase(b.begin()+j-1);
                break;
            }
        }
    }
    if(ans.size() == c.size()){
        reverse(all(ans));
        rep(i,ans.size()){
            cout << ans[i] << endl;
        }
    }else {
        cout << -1 << endl;
    }
    cout << endl;
    return 0;
}
