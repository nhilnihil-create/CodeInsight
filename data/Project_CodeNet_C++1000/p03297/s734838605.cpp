#include <bits/stdc++.h>
#define ll long long
#define Nope {puts("No");continue;}
#define  Yep {puts("Yes");continue;}
using namespace std;
ll T,A,B,C,D;
ll exgcd(ll a,ll b,ll&x,ll&y) {
    if(b==0) {
        x=1,y=0;
        return a;
    }
    ll t=x,ret=exgcd(b,a%b,y,x);
    x=y,y=t-a/b*y;
    return ret;
}
int main() {
    scanf("%lld",&T);
    while(T--) {
        scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
        if(A<B) Nope;
        if(D<B) Nope;
        if(C+1>=B) Yep;
        /**
        此时有：A>=B D>=B C+1<B
        A-Bx+Dy==T（补完货还没有来买时）
        Bx-Dy=A-T
        A-C>Bx-Dy>A-B
        有C<T
        为什么T>C?
        如果有一天T<C,假设这是T<C的第一天（一定存在）
        那么前一天TT（补完货还没有来买时）一定大于C
        那么有C<TT<=TT-B+D(D>=B)=T<C,产生了矛盾
        而此时如果有B>T,那么一定会有第二天一早买不了的情况发生
        为什么一定会有
        */
        ll x,y,gcd;
        //gcd=exgcd(B,D,x,y);
        gcd=__gcd(B,D);
        //cout<<gcd<<endl;
        if((A-C-1)/gcd-(A-B)/gcd>0) Nope
        else Yep


    }
    return 0;
}
