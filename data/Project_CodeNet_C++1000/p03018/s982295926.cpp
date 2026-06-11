#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    ll ans = 0;
    rep(i,s.size()-1){
        if(s[i]=='A'){
            cnt ++;
        }
        else if(s[i]=='B'&&s[i+1]=='C'){
            ans += cnt;
            ++i;
        }
        else{
            cnt = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
