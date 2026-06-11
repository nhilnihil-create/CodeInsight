#include<bits/stdc++.h> 
//#include<atcoder/all>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
//using namespace atcoder;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int ans = 0;
    vector<int> a(3); 
    rep(i, n){
        if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A') a[0]++;
        else if (s[i][0] == 'B') a[1]++;
        else if (s[i][s[i].size() - 1] == 'A') a[2]++;
        rep(j, s[i].size() - 1){
            if (s[i][j] == 'A' && s[i][j + 1] == 'B')
                ans++;
        }
    }
    if (a[0]) ans += a[0] - 1;
    if (a[0] && a[1]) ans++;
    if (a[0] && a[2]) ans++;
    if (a[0] && a[1] && a[2]) ans += min(a[1], a[2]) - 1;
    else if (a[1] && a[2]) ans += min(a[1], a[2]);
    cout << ans << endl;
}