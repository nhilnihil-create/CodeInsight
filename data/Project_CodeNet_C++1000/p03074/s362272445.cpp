#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(s.at(n-1) == '0'){
        s += '1';
    }else{
        s += '0';
    }
    vector<vector<int>> a(0, vector<int>(2));
    rep(i, n){
        if(s.at(i+1) != s.at(i)){
            a.push_back({i+1, s.at(i) - '0'});
        }
    }
    int cou = 0;
    rep(i, a.size()){
        if(a.at(i).at(1) == 0) cou++;
    }
    int sum = 0;
    int ans = 0;
    int asi = a.size();
    k = min(k, cou);
    if(n != 1){
        if(asi != 1){
            rep(i, asi){
                if(a.at(i).at(1) == 1) continue;
                if(i+(k-1)*2 > asi-1) break;
                int st = max(0, i-1);
                int fi = min(asi-1, i+(k-1)*2+1);
                if(st == 0){
                    sum = a.at(fi).at(0);
                }else{
                    sum = a.at(fi).at(0) - a.at(st-1).at(0);
                }
                if(ans < sum) ans = sum;
            }
        }else{
            ans = n;
        }
    }else{
        ans = 1;
    }
    cout << ans << endl;
    return 0;
}