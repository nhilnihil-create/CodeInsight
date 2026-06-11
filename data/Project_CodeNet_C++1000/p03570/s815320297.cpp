#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define lg length()
#define pb push_back
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005

string s;

int n,p[67108870],t,ans;

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> s;
    n=s.lg; t=0;
    for(int i=0;i<(1<<26);i++){
        p[i]=1e9;
    }
    p[0]=0;
    for(int i=1;i<=n;i++){
        int b=1<<(s[i-1]-'a');
        t^=b;
        ans=p[t]+1;
        for(int i=0;i<26;i++){
            b=t^(1<<i);
            ans=min(ans,p[b]+1);
        }
        p[t]=min(p[t],ans);
        //cout << ans << ' ';
    }
    cout << ans;
}
