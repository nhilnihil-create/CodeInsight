#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using pint = pair<int, int>;
using pll = pair<ll,ll>;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    vector<int> a(26,0),b(26,0);
    for(char x:s1){
        x-=97;
        a[x]++;
    }
    for(char x:s2){
        x-=97;
        b[x]++;
    }
    sort(a.begin(),a.end(),greater<>());
    sort(b.begin(),b.end(),greater<>());
    bool flag = true;
    for(int i=0;i<26;i++){
        if(a[i]!=b[i])flag=false;
    }
    if(flag)COUT("Yes");
    else COUT("No");
    return 0;
}