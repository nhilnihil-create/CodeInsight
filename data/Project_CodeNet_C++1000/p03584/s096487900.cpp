#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt,ans,a[ohara],b[ohara],c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
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

    cin>>n>>k;
    rep(i,n)cin>>a[i]>>b[i];
    c=k;
    while(1){
        c/=2;
        d++;
        if(c==0)break;
    }
    //cout<<"\n";
    tmp=0;
    rrrep(i,d,0){
        if((k&(1LL<<i))!=0){
            tmpp=0;
            if(tmp<k){
            rrep(j,0,i){
            tmpp=(tmpp|(1LL<<j));
            }
            }
            if((tmp|tmpp)<=k){
            pos=(tmp|tmpp);
            }
            else{
                pos=tmp;
            }
            if(i==0)pos=k;
            rep(j,n){
                if((pos|a[j])==pos)cnt+=b[j];
            }
            //cout<<i<<" "<<pos<<"\n";
            ans=max(ans,cnt);
            //Cout(cnt);
            tmp=(tmp|(k&(1LL<<i)));
            cnt=0;
        }
    }
    rep(i,n){
        if((k|a[i])==k)cnt+=b[i];
    }
    Cout(max(ans,cnt));
    return 0;
}
