#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<string> w(n);
    map<string,int> m;
    rep(i,n) cin >> w[i];
    rep(i,n) m[w[i]]++;
    bool flag = true;
    rep(i,n-1) if(w[i][w[i].size()-1] != w[i+1][0]) flag = false;
    for(auto p : m) if(p.second > 1) flag = false;
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}