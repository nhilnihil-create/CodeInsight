#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
#define N 105
#define inf 0x3fffffff
#define rep(i, l, r) for(int i=l; i<=r; ++i)
using namespace std;
int n;
struct node{
    int x, y;
    ll h;
    void read(){scanf("%d%d%lld", &x, &y, &h);}
}a[N];
int main(){
    scanf("%d", &n);
    int pos=1;
    rep(i, 1, n){
        a[i].read();
        if(a[i].h) pos=i;
    }
    rep(cx, 0, 100){
        rep(cy, 0, 100){
            ll h=a[pos].h+abs(cx-a[pos].x)+abs(cy-a[pos].y);
            bool f=true;
            rep(i, 1, n){
                if(a[i].h!=max(h-abs(cx-a[i].x)-abs(cy-a[i].y), 0ll)) f=false;
            }
            if(f){
                printf("%d %d %d", cx, cy, h);
                return 0;
            }
        }
    }
    return 0;
}