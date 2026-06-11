#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
#define f2(i,j,k) for(int i=j;i>k;i--)
using namespace std;
int main(){
    long long a[3],n,ans=0;
    cin>>a[0]>>a[1]>>a[2]>>n;
    sort(a,a+3);
    f(i,0,n/a[0]+1){
        f(j,0,(n-a[0]*i)/a[1]+1){
            if((n-a[0]*i-a[1]*j)%a[2]==0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
