#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=1000000007;
const double pi=3.1415926535897932,eps=1e-6;
int n,m,k,x,y,mp[128],px[5],py[5],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
char s[200005],t[200005];
void fail(){puts("NO");exit(0);}
bool valid(int x,int y){
    return (x>=1 && x<=n) && (y>=1 && y<=m);
}
int main()
{
    scanf("%d%d%d%d%d%s%s",&n,&m,&k,&x,&y,s+1,t+1);
    mp['U']=0; mp['D']=1; mp['L']=2; mp['R']=3;
    rep(i,0,3) px[i] = x, py[i] = y;
    rep(i,1,k) rep(j,0,3){
        int jj = j ^ 1;
        if(mp[s[i]] == j){
            px[j] += dx[j];
            py[j] += dy[j];
            if(!valid(px[j],py[j])) fail();
        }
        if(mp[t[i]] == jj){
            if(valid(px[j] + dx[jj], py[j] + dy[jj])) {
                px[j] += dx[jj];
                py[j] += dy[jj];
            }
        }
    }
    puts("YES");
    return 0;
}