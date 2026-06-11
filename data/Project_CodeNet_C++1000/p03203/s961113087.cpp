#include <bits/stdc++.h>
typedef long long ll;
const int INF=1e9,MOD=1e9+7,ohara=1e6;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt,ans,a,b,c,d,tmp,tmpp,m,h,w,x[ohara],y[ohara],sum,pos,lim=1;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool visited[ohara];
struct edge{int to,cost;};
unordered_map<ll,ll> mp;

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);
      
    cin>>h>>w>>n;
    rep(i,n)cin>>x[i]>>y[i];
    rep(i,n){
        if(!visited[x[i]])mp[x[i]]=y[i],visited[x[i]]=true;
        else mp[x[i]]=min(mp[x[i]],y[i]);
    }
    ans=h;
    rrep(i,2,h+1){
        //cout<<i<<" "<<lim<<"\n";
        if(!visited[i]){
            lim++;
        }
        else{
        tmp=mp[i];
        //cout<<i<<" "<<tmp<<" "<<lim<<"\n";
        if(lim+1==tmp){
            continue;
        }
        else if(lim+1<tmp){
            lim++;
        }
        else{
            ans=i-1;
            break;
        }
        }
    }
    Cout(ans);
    return 0;
}
