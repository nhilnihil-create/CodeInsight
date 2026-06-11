#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main(){
    string s; cin>>s;
    int ans=0;

    if(s[0]=='A') ans++;
    int cnt=0;
    rep(i,2,s.size()-1){
        if(s[i]=='C'){
            cnt++;
            s[i]='c';
        }
    }
    // cout<<s<<endl;
    if(cnt==1) ans++;
    // cout<<ans<<endl;
    bool ok=true;
    rep(i,1,s.size()){
        if(s[i]>'Z'){
            continue;
        }else ok=false;
    }
    // if('C'<'A') cout<<"Yes"<<endl;
    if(ok) ans++;

    if(ans==3) cout<<"AC"<<endl;
    else cout<<"WA"<<endl;
}