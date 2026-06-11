#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int T;
ll a,b,c,d;

ll gcd(ll a,ll b){
    return a%b==0?b:gcd(b,a%b);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a<b){
            printf("No\n");
            continue;
        }
        if(b>d){
            printf("No\n");
            continue;
        }
        if(c+1>=b){
            printf("Yes\n");
            continue;
        }
        ll cxz=gcd(b,d);
        if((a-c-1)/cxz>(a-b)/cxz)
            printf("No\n");
        else
            printf("Yes\n");
    }
}
