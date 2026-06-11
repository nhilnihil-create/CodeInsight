#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;

ll gcd(ll a ,ll b){
    return b?gcd(b,a%b):a;
}

int check(ll A,ll B,ll C,ll D){
    if(A<B||D<B)return 0;
    ll g = gcd(B,D);
    if((A-C-1)/g-(A-B)/g >0)
            return 0;
        else
            return 1;

/*    A %= B;
    if(D%B == 0){
        if(A<=C)return 1;
        else return 0;
    }
    if(D>=B){
        D %= B;
        if(A<B&&A>C)return 0;
/*        while(A <= C){
            A += D;
        }*/
/*        ll temp = (C-A)/D+1;
        A = A + temp*D;
        if(A<B&&A>C)return 0;
        else return 1;
    }
*/
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll a,b,c,d;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if(check(a,b,c,d))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
