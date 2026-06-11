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

    string s;
    cin >> s;
    int k;
    cin >> k;
    bool all_one = true;
    char ans = '1';
    for(int i = 0; i < k; i++){
        if(s[i] != '1'){
            ans = s[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
