#include <iostream>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n,a[N],b[N];
int main() {
    scanf("%d",&n);
    int mn=1e9+7;
    LL s=0,tmp=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        if(a[i]==b[i]){
            tmp+=a[i];
            continue;
        }
        if(a[i]>b[i])mn=min(mn,b[i]);
        s+=a[i]+b[i];
    }
    if(mn==1e9+7) return !printf("0\n");
    cout<<(s-2*mn)/2+tmp<<endl;
}

