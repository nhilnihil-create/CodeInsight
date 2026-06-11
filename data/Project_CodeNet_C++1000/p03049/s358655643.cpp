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
const ll mod = 1000000007;
 
int main() {
    int n;
    cin >> n;
    int cnt1=0,cnt2=0,cnt3=0, ans=0;  
    rep(i, 0, n){
        string a;
        cin >> a;
        int m = a.size();
        rep(j, 0, m-1){
            if(a[j]=='A'&&a[j+1]=='B')ans++;
        }
        if(a[0]!='B'&& a[m-1]=='A')cnt1++;
        if(a[0]=='B'&& a[m-1]!='A')cnt2++;
        if(a[0]=='B'&& a[m-1]=='A')cnt3++;
    }
    //cout << ans << endl;
    if(cnt1>cnt2){
        ans += cnt2+cnt3;
    }
    if(cnt1<cnt2){
        ans += cnt1+cnt3;
    }
    if(cnt1 == cnt2){
        if(cnt1==0)ans += max(0, (cnt3 -1)); 
        else ans += cnt1+cnt3;
    }
    cout << ans << endl;
    //cout << cnt1 << cnt2 << cnt3 << endl;
}