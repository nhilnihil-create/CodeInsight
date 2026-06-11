#include<bits/stdc++.h>
#define M 1000000007
#define pi ld(acos(-1.0))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(ll i=a;i<=(ll)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define ii pair<int,int>
#define bye(x) {cout<<x;return 0;}
typedef long long ll;
typedef long double ld;
using namespace std;
ll n;
bool check(string &s) {
    bool a=0,b=0,c=0;
    for(auto i:s) {
        if(i=='7') a=1;
        else if(i=='5') b=1;
        else if(i=='3') c=1;
    }
    return a&&b&&c;
}
int dfs(string s) {
    if(stoll(s)>n) return 0;
    int t=check(s);
    t+=dfs(s+'3');
    t+=dfs(s+'5');
    t+=dfs(s+'7');
    return t;
}

int main() {
    cs
    cin>>n;
    cout<<dfs("0");
}