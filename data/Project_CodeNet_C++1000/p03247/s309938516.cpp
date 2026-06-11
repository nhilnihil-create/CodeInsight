#include <iostream>
#include <cmath>
using namespace std;
const int N=1002;
typedef long long LL;
int n;
LL x[N],y[N];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char op[4]={'R','L','U','D'};
void solve(LL x,LL y){
    // 2^k  [0,2^{k+1}-1]
    string ans=""; 
    bool fg=0;
    if((x+y)%2==0)--x,fg=1;
    for(int k=30;k>=0;k--){
        //printf("k=%d,x=%lld,y=%lld\n", k,x,y);
        for(int i=0;i<4;i++){
            LL nx=x+dx[i]*(1LL<<k);
            LL ny=y+dy[i]*(1LL<<k);
            //printf("nx=%lld,ny=%lld\n", nx,ny);
            if(abs(nx)+abs(ny)<=((1LL<<k)-1)) {
                //printf("k=%d\n", k);
                x=nx, y=ny; ans=op[i]+ans;
                break;
            }
        }
    }   
    //printf("%d %d\n", x, y);
    if(fg){
        ans=ans+'R';
    }
    cout<<ans<<endl;

    LL px=0,py=0;
    for(int i=0;ans[i];i++){
        int o=0;
        if(ans[i]=='R')o=1;
        if(ans[i]=='U')o=3;
        if(ans[i]=='D')o=2;
        px+=dx[o]*(1LL<<i);
        py+=dy[o]*(1LL<<i);
    }
    //printf("# %lld %lld\n", px,py);
}
int main() {    
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
    for(int i=1;i<=n;i++){
        if( ((x[i]+y[i])%2==0) != ((x[1]+y[1])%2==0) ) return !printf("-1\n");
    }
    if((x[1]+y[1])%2!=0) {
        printf("31\n");
        for(int i=0;i<=30;i++)printf("%lld ", 1LL<<i);
        printf("\n");
    } else {
        printf("32\n");
        for(int i=0;i<=30;i++)printf("%lld ", 1LL<<i);
        printf("1\n");
    }
    for(int i=1;i<=n;i++){
        solve(x[i],y[i]);
    } 
}
