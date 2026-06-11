#include <bits/stdc++.h>
typedef long long ll;
const int INF=1e9,MOD=1e9+7,ohara=1e6;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrrep(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt,ans,a,b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,Q,k;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);
      
    cin>>n>>s>>Q;
    rep(i,Q){
        cin>>k;
        d=0;m=0;cnt=0;ans=0;
        rep(i,n){
            if(s[i]=='D')d++;
            else if(s[i]=='M')cnt+=d,m++;
            else if(s[i]=='C')ans+=cnt;
            if(i>=k-1){
                if(s[i-k+1]=='D')cnt-=m,d--;
                else if(s[i-k+1]=='M')m--;
            }
        }
        Cout(ans);
    }
    return 0;
}
