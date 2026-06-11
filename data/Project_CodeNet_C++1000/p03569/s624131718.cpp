#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
 
int main() {
    string s;
    cin >> s;
    string s2;
    int n = s.size();
    vector<int>a;
    int cnt=0;
    rep(i, 0, n){
        if(s[i]=='x'){
            cnt++;
        }else{
            a.push_back(cnt);
            cnt =0;
            s2 += s[i];
        }
    }
    a.push_back(cnt);
    string s3 = s2;
    reverse(s2.begin(),s2.end());
    if(s2 != s3){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0, m = a.size()/2;
    rep(i, 0, m){
        if(a[i] != a[(a.size()-1)-i])ans += abs(a[i]-a[(a.size()-1)-i]);
    }
    cout << ans << endl;
}