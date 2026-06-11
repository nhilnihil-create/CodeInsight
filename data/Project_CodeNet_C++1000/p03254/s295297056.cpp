#include <bits/stdc++.h>
using namespace std;
#define f(i,j,k) for(int i=j;i<k;i++)
int main(){
    long long n,x,ans=0;
    cin>>n>>x;
    long long a[n];
    f(i,0,n){
        cin>>a[i];
    }
    sort(a,a+n);
    f(i,0,n){
        if(i!=n-1&&x>=a[i]){
            x-=a[i];
            ans++;
        }
        else if(i==n-1&&x==a[i]){
            ans++;
        }
        else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}