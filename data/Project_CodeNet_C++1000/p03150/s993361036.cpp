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
    int n = s.size();
    string t = "keyence";
    bool flag = false;
    REP(i,n){
        FOR(j,i,n+1){
            string tmp = s.substr(0,i)+s.substr(j);
            if(tmp == t)flag=true;
        }
    }
    
    if(flag)COUT("YES");
    else COUT("NO");
    return 0;
}    