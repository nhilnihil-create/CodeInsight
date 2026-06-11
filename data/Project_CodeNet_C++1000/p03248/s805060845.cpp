#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ffor(i,n) for(int i = 0;i < (n); ++i)
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vi>
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    string s;
    cin >> s;
    int n = s.length();
    if(s[0] != '1' || (s[n - 1] != '0')){
        cout << -1;
        return 0;
    }
    int k = 0;
    vi pts;
    for(int i = 0;i < n; ++i){
        if(n - i - 2 >= 0 && (s[i] != s[n - i - 2])){
            cout << -1;
            return 0;
        }
        if(s[i] == '1'){
            ++k;
            pts.push_back(i + 1);
        }
    }
    int i = 1;
    for(;i <= k; ++i){
        cout << i << ' ' << i + 1 << '\n';
    }
    ++i;
    for(int rt = 1;rt < pts.size(); ++rt){
        int tot = pts[rt] - pts[rt - 1] - 1;
        while(tot--){
            cout << rt + 1 << ' ' << i << '\n';
            ++i;
        }
    }
}