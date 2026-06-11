#include<bits/stdc++.h>
#define ll long long
#define pii_ pair<int,int>
#define mp_ make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define show1(a) cout<<#a<<" = "<<a<<endl
#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl
using namespace std;
const ll INF = 1LL<<60;
const int inf = 1<<30;
const int maxn = 2e5+5;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
char s[maxn];
bool check()
{
    int n = strlen(s+1);
    if(s[1]!='1' || s[n]!='0') return false;
    rep(i,1,n-1){
        if(s[i]!=s[n-i]) return false;
    }
    return true;
}

int main()
{
    fastio();
    cin>>s+1;
    int n=strlen(s+1);
    if(!check()) {cout<<-1<<endl;return 0;}
    int cnt = 0;
    rep(i,1,n) if(s[i]=='1') cnt++;
    rep(i,1,cnt) cout<<i<<" "<<i+1<<endl;
    int last = 1,now=cnt+2,c=1;
    rep(i,2,n){
        if(s[i]=='1'){
            c++;
            int t = i-last-1;
            rep(j,1,t) cout<<c<<" "<<now++<<endl;
            last = i;
        }
    }
    return 0;
}
