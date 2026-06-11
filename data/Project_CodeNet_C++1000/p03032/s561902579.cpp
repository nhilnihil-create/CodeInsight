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
    
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    int ans=0;
    vector<int> l;
    for(int i=0; i<=min(k,n); ++i){
        if(i!=0) l.push_back(v[i-1]);
        vector<int> r=l;
        for(int j=n; j>=n-k+i;--j){
            if(j!=n && (i-1)<j) r.push_back(v[j]);
            int pr=0,cnt=0;
            sort(r.begin(),r.end());
            for(auto u : r){
                if(u<0 && cnt<(k-i-(n-j))){
                    ++cnt;
                    continue;
                }
                pr+=u;
            }
            ans=max(ans,pr);
        }
    }
    cout << ans << "\n";
    return 0;
}   