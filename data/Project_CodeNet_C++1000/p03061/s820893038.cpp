#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int main(){
    
    int n;
    int a[100005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l[100005]={},r[100005]={};
    for(int i=0;i<n-1;i++){
        if(i==0){
            l[i] = gcd(a[i],a[i+1]);
        }
        else l[i] = gcd(l[i-1],a[i+1]);
    }
    reverse(a,a+n);
    for(int i=0;i<n-1;i++){
        if(i==0){
            r[i] = gcd(a[i],a[i+1]);
        }
        else r[i] = gcd(r[i-1],a[i+1]);
    }
    reverse(r,r+n-1);
    reverse(a,a+n);
    
    if(n==2){
        cout<<max(a[0],a[1])<<endl;
    }
    else if(n==3){
        cout<<max(gcd(a[0],a[2]),max(l[0],r[1]))<<endl;
    }
    else{
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==0) ans = max(ans,r[1]);
            else if(i==1) ans = max(ans,gcd(a[0],r[2]));
            else if(i==n-2) ans = max(ans,gcd(a[n-1],l[i-2]));
            else if(i==n-1) ans = max(ans,l[i-2]);
            else ans = max(ans,gcd(l[i-2],r[i+1]));
        }
        cout<<ans<<endl;
    }
    
    
    return 0;
}



