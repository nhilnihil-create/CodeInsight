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

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> west(n, 0);
    vector<int> east(n, 0);
    for(int i = 0; i < n; i++){
        if(i > 0){
            west[i] = west[i-1];
            east[i] = east[i-1];
        }
        if(s[i] == 'W') west[i]++;
        else if(s[i] == 'E') east[i]++;
    }
    int ans = INF;
    for(int i = 0; i < n; i++){
        int v;
        if(i > 0){
            v = west[i-1] + (east[n-1] - east[i]);
        }
        else{
            v = east[n-1] - east[i];
        }
        ans = min(ans, v);
    }
    cout << ans << endl;
    return 0;
}
