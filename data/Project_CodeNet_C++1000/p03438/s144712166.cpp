#include<cstdio>
using namespace std;
typedef long long ll;
const int N=10000+10;
int n;
ll a[N];
int main() {
    while(~scanf("%d",&n)){
        ll x;
        ll n1=0,n2=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%lld",&x);
            if(x>a[i]){
                if((x-a[i])%2==1){n2++;n1+=((x+1)-a[i])/2;}
                else {n1+=(x-a[i])/2;}
            }
            else {
                n2+=(a[i]-x);
            }
 
        }
 
        if(n1>=n2) printf("Yes\n");
        else {
            printf("No\n");
        }
    }
 
    return 0;
}