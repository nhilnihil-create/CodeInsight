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
    int cnt_0, cnt_1;
    cnt_0 = cnt_1 = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '0') cnt_0++;
        else cnt_1++;
    }
    cout << 2 * min(cnt_0, cnt_1) << endl;
    return 0;
}