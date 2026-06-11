#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    ll a=0,b=0,ab=0;
    ll cnt = 0;
    rep(i,n){
        rep(j,s[i].size()-1){
            if(s[i][j]=='A' && s[i][j+1]=='B'){
                cnt++;
            }
        }
        int h = s[i].size()-1;
        if(s[i][0]=='B') b++;
        if(s[i][h]=='A') a++;
        if(s[i][0]=='B' && s[i][h]=='A') ab++;
    }
    ll ans = cnt + min(a,b);
    //cout << a << " " << b << " " << ab << endl;
    if(ab>0 && a+b==0) ans--;
    if(a == ab && b == ab && ab>0) ans--;
    cout << ans << endl;
}