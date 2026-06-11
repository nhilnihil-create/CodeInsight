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

ll n,cnt=0,a,b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s,ans[501][501];
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);
      
    cin>>a>>b;a--;b--;
    rep(i,100){
        rep(j,100){
            if(i<50)ans[i][j]='.';
            else ans[i][j]='#';
        }
    }
    rep(i,50){
        rep(j,100){
            if(b==0)break;
            if(i%2==0){
                if(j%2==0){
                    ans[i][j]='#';
                    b--;
                }
            }
            if(b==0)break;
        }
        if(b==0)break;
    }
    rrep(i,50,100){
        rep(j,100){
            if(a==0)break;
            if(i%2!=0){
                if(j%2==0){
                    ans[i][j]='.';
                    a--;
                }
            }
            if(a==0)break;
        }
        if(a==0)break;
    }
    cout<<"100 100\n";
    rep(i,100){
        rep(j,100){
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
