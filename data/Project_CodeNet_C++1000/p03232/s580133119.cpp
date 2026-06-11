#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 200000+10;
int n; LL a[N],inv[N];
int main() {
    inv[1]=1;
    for(int i=2;i<N;i++){
        inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
    }
    for(int i=1;i<N;i++){
        inv[i]+=inv[i-1]; inv[i]%=MOD;
    }
    scanf("%d",&n);
    LL res=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        res+=a[i]*(inv[i]+inv[n-i+1]-1)%MOD;
        res%=MOD;
    } 
    for(int i=1;i<=n;i++) res=res*i%MOD;
    cout<<res<<endl;
}