#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
int n;
long long a, b, l;
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%lld%lld", &a, &b);
        if(a>b)std::swap(a, b);
        if(a==b)printf("%d\n", a*2-2);
        else if(a+1==b)printf("%d\n",a*2-2);
        else{
            l=floor(sqrt(a*b));
            while(l*l<a*b)l++;
            l--;
            if(l*(l+1)>=a*b)printf("%d\n", l*2-2);
            else printf("%d\n", l*2-1);
        }
    }
    return 0;
}