#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int m,n,r=100001,l=0,a,b;
    cin >> n >> m;
    rep(i,m){
        cin >> a >> b;
        l=max(l,a);
        r=min(r,b);
        if(l>r){
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << r-l+1 << "\n";
    return 0;
}