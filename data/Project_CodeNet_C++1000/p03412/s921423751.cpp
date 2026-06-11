#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int man = 2e5+10;
template<typename T>T gcd(T a, T b) {return b==0?a:gcd(b, a%b);}
template<typename T>T exgcd(T a,T b,T &g,T &x,T &y){if(!b){g = a,x = 1,y = 0;}else {exgcd(b,a%b,g,y,x);y -= x*(a/b);}}
template<typename T>T quick_add(T a,T b,T mod){T ans = 0;while(b){if(b&1)ans = (ans+a)%mod;a = (a+a)%mod;b /= 2;};return ans%mod;}
template<typename T>T quick_mod(T a,T b,T mod){T ans = 1;while(b){if(b&1)ans = ans*a%mod;a = a*a%mod;b /= 2;};return ans%mod;}
#ifndef ONLINE_JUDGE
#define debug(fmt, ...) {printf("debug ");printf(fmt,##__VA_ARGS__);puts("");}
#else
#define debug(fmt, ...)
#endif
typedef long long ll;
const ll mod = 1e9+7;
int a[man],b[man],c[man],d[man];
int n;

inline int erfen_L(int maxx){
    int l = 1,r = n;
    int ans = -1;
    while(l<=r){
        int mid = l+r>>1;
        if(c[mid]>=maxx){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    return ans;
}

inline int erfen_R(int maxx){
    int l = 1,r = n;
    //cout << "maxx:" << maxx <<endl;
    int ans = -1;
    while(l<=r){
        int mid = l+r>>1;
        if(c[mid]<maxx){
           //if(maxx==1)cout << "mid:" << mid << " c:" << c[mid] << endl;
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    return ans;
}
  
int main() {
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i = 1;i<= n;i++){
        scanf("%d",&a[i]);
    }   
    for(int i = 1;i <= n;i++){
        scanf("%d",&b[i]);
    }
    int ans = 0;
    for(int k = 1;k <= 30;k++){
        for(int i = 1;i <= n;i++){
            c[i] = a[i]&((1<<k)-1);
            d[i] = b[i]&((1<<k)-1);
        }
        sort(c+1,c+1+n);
        int tp = 0;
        for(int i = 1;i <= n;i++){
            int l = erfen_L((1<<(k-1))-d[i]);
            int r = erfen_R((1<<k)-d[i]);
            if(l!=-1&&r!=-1)tp += (r-l+1);
            l = erfen_L((1<<k)+(1<<(k-1))-d[i]);
            r = erfen_R((1<<(k+1))-d[i]);
            if(l!=-1&&r!=-1)tp += (r-l+1);
        }
		if(tp%2)ans += (1<<(k-1));
    }
    printf("%d\n",ans);
    return 0;
}
