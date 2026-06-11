#include<iostream>
using namespace std;

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int main(){
    int n;cin>>n;
    int a[n],l[n],r[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        if(i == 1){
            l[i]=a[i-1];
            r[n-1-i]=a[n-i];
        }
        else{
            l[i] = gcd(l[i-1],a[i-1]);
            r[n-1-i] = gcd(r[n-i],a[n-i]);
        }
    }
    int ans=0;
    int tmp;
    for(int i=0;i<n;i++){
        if(i==0) tmp=r[0];
        else if(i==n-1) tmp=l[n-1];
        else tmp=gcd(l[i],r[i]);
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}