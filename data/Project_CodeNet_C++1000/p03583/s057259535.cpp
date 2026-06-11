#include<bits/stdc++.h>
using namespace std;
long long n;
void out(long long x,long long y,long long z){
    cout<<x<<" "<<y<<" "<<z;
    exit(0);
}
void f(){
    long long c,m;
    for(long long i=1;i<=3500;i++)
        for(long long j=1;j<=3500;j++){
            c=n*i*j;
            m=4*i*j-n*i-n*j;
            if(m>0&&c%m==0)out(i,j,c/m);
        }
}
int main(){
    cin>>n;
    if(n%2==0)out(n,n,n/2);
    if(n%3==0)out(n,n/3*2,n/3*2);
    if((n-3)%4==0)out((n+1)/4,(n+1)*(n+1)/4,(n+1)*(n+1)*n/4);
    if((n-1)%4==0)f();
}