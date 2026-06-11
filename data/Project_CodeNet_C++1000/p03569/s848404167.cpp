#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s;
    cin >> s;
    string t;
    vector<int> num;
    int cnt = 0;
    rep(i,s.size()){
        if(s[i]!='x') {
            t.push_back(s[i]);
            num.push_back(cnt);
            cnt = 0;
        }else cnt++;
    }
    num.push_back(cnt);

    rep(i,t.size()/2){
        if(t[i] != t[t.size()-i-1]){
            cout << -1 << endl;
            return 0;
        }
    }
    int ans = 0;
    rep(i,(t.size()+1)/2) ans += abs(num[i] - num[t.size()-i]);
    cout << ans << endl;
}