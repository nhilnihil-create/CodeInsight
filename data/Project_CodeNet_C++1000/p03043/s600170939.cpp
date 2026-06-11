#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long k;
    double n;
    cin>>n>>k;
    double ans=0;
    f(i,1,n+1){
        long double a=1/n;
        long long now=i;
        while(now<k){
            now*=2;
            a/=2;
        }
        ans+=a;
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}
