#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}
int main(){

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int l[q], r[q];
    int cnt[n+1] = {0};
    for(int i = 0; i < n; i++){
        if(s.substr(i, 2) == "AC"){
            cnt[i+1] = cnt[i] + 1;
        }
        else{
            cnt[i+1] = cnt[i];
        }
    }

    for(int i = 0; i < q; i++){
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    for(int i = 0; i < q; i++){
        cout << cnt[r[i]] - cnt[l[i]] << endl;
    }
    return 0;
}