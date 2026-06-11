#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<endl

int main(){
    string s;
    cin >> s;
    int ans = s[0]-'0';
    bool flag = true;
    FOR(i,1,s.size()){
        if(s[i]!='9')flag = false;
    }
    if(flag) ans += (s.size()-1)*9;
    else ans += (s.size()-1)*9-1;
    COUT(ans);
    return 0;
}