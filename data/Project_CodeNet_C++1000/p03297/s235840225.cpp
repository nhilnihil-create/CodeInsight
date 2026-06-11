#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
typedef long long ll;
int n;
ll a,b,c,d;
ll gcd(ll x,ll y){
    if(y==0)
        return x;
    return gcd(y,x%y);
}
int main(){
    SF("%d",&n);
    while(n--){
        SF("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a<b){
            PF("No\n");
            continue;
        }
        if(b>d){
            PF("No\n");
            continue;
        }
        if(c+1>=b){
            PF("Yes\n");
            continue;
        }
        ll g=gcd(b,d);
        if((a-c-1ll)/g-(a-b)/g>0)
            PF("No\n");
        else
            PF("Yes\n");
    }
} 