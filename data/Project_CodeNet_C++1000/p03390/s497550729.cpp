#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int q;
ll a,b;
int main(){
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%lld%lld",&a,&b);
        if (a > b)swap(a,b);
        ll s = floor(sqrt(a*b));
        if (s == a)s++;
        ll t = (a*b-1)/s;
        if (t == b)t--;

        printf("%lld\n", s + t - 2);
    }
}
