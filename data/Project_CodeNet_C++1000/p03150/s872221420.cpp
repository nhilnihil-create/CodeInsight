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
    string t = "keyence";
    bool flag = false;
    
    //keyenceが固まって存在している場合
    REP(i,s.size()-7){
        string st = s.substr(i,7);
        if(st==t) flag = true;
    }
    //keyenceがばらけている場合
    FOR(i,1,7){
        string st1 = s.substr(0,i);
        string st2 = s.substr(s.size()-7+i,7-i);
        if(st1+st2==t) flag = true;
    }
    if(flag)COUT("YES");
    else COUT("NO");
    return 0;
}    
