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

ll n,cnt=0,ans=0,a,b,d,cmp,cmpp,m,h,w,x[ohara],v[ohara],y,sum=0,pos,c;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
ll ans1=0,ans2=0,ans3=0,ans4=0;
ll access3[ohara];
ll access4[ohara];
ll cou3=0,cou4=0;
ll tmp3,tmp4;

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);
      
    cin>>n>>c;
    rep(i,n)cin>>x[i]>>v[i];
    rep(i,n){
        cnt+=v[i];
        if(i!=n-1){
        access4[cou4++]=cnt-x[i];
        }
        ans1=max(ans1,cnt-x[i]);
    }
    cnt=0;
    rrrep(i,n-1,0){
        cnt+=v[i];
        if(i!=0){
        access3[cou3++]=cnt-c+x[i];
        }
        ans2=max(ans2,cnt-c+x[i]);
    }
    rrep(i,1,cou3){
        access3[i]=max(access3[i],access3[i-1]);
    }
    rrep(i,1,cou4){
        access4[i]=max(access4[i],access4[i-1]);
    }
    reverse(access3,access3+cou3);
    //reverse(access4,access4+cou4);
    cnt=0;
    rep(i,n-1){
        cnt+=v[i];
        tmp3=cnt-x[i];
        tmp3+=access3[i];
        tmp3-=x[i];
        ans3=max(ans3,tmp3);
    }
    cnt=0;
    rrrep(i,n-1,1){
        cnt+=v[i];
        tmp4=cnt-c+x[i];
        tmp4-=c-x[i];
        tmp4+=access4[i-1];
        ans4=max(ans4,tmp4);
    }
    Cout(max({ans1,ans2,ans3,ans4}));
    return 0;
}
