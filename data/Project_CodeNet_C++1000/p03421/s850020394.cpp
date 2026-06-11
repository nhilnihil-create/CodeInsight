#include<bits/stdc++.h>
using namespace std;
long long n,a,b;
int main(){
    cin>>n>>a>>b;
    if(a+b>n+1||a*b<n){
        cout<<-1;
        return 0;
    }
    while(n>0){
        long long x=min(a,n-b+1);
        for(long long i=n-x+1;i<=n;i++)cout<<i<<" ";
        n-=x;b--;
    }
    return 0;
}