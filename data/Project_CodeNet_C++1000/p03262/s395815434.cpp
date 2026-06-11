#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int gcd(long long s,long long t){
    if(s%t==0){
        return t;
    }
    else{
        return gcd(t,s%t);
    }
}
int main(){
    long long n,x;
    cin>>n>>x;
    long long a[n];
    f(i,0,n){
        cin>>a[i];
        a[i]=abs(a[i]-x);
    }
    long long ans=a[0];
    f(i,0,n){
        ans=gcd(ans,a[i]);
    }
    cout<<ans<<endl;
    return 0;
}