#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9,MOD = 1e9+7,ohara = 1e6;
const ll LINF = 1e18;
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrrep(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt=0,ans=0,a,b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos,grid[3000][3000];
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
      
    cin>>n;
    ll tate=0,yoko=0;
   rrep(i,2,100000){
        pos=i*(i-1);
        if(pos/2==n){
            tate=i;
            yoko=i-1;
            break;
        }
    }
    if(pos/2!=n)Cout("No");
    else{
        Cout("Yes");
        Cout(tate);
        rep(i,yoko)grid[0][i]=i+1;
        ll gen=yoko;
        rrep(i,1,tate){
            rep(j,yoko){
                if(j<i){
                        grid[i][j]=grid[j][i-1];
                }
                else{
                    gen++;
                    grid[i][j]=gen;
                   // gen++;
                }
            }
        }
        rep(i,tate){
            cout<<yoko<<" ";
            rep(j,yoko){
                if(j!=yoko-1){
                cout<<grid[i][j]<<" ";
                }
                else cout<<grid[i][j]<<"\n";
            }
            //cout<<"\n";
        }
    }
    return 0;
}
