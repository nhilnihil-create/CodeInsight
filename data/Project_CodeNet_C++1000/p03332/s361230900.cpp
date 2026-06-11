#include <iostream>
using namespace std;

long long p = 998244353;
long long mod_fact[300008];

void mod_fact_init(){
    mod_fact[0]=mod_fact[1]=1;
    for(int i=2;i<300008;i++)
        mod_fact[i]=(mod_fact[i-1]*i)%p;
}


long long mod_pow(long long a, long long b){
    a%=p;
    if(b==0)
        return 1;
    else if(b%2==0)
        return mod_pow(a*a, b/2)%p;
    else
        return (a*mod_pow(a, b-1))%p;
}

long long mod_comb(long long a, long long b){
    long long c = (mod_fact[a]*mod_pow(mod_fact[a-b], p-2))%p;
    return (c*mod_pow(mod_fact[b], p-2))%p;
}

int main(void){
    long long n,a,b,k,m=0;
    cin>>n>>a>>b>>k;
    mod_fact_init();
    for(long long i=0;i<=min(k/a,n);i++){
        if((k-i*a)%b==0){
            long long j=(k-i*a)/b;
            if(j<=n)m=(m+(mod_comb(n,i)*mod_comb(n,j))%p)%p;
        }
    }
    cout<<m<<endl;

    return 0;
}
