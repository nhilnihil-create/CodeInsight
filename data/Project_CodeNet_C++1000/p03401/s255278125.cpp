#include<bits/stdc++.h>                          
using namespace std;
int n,sum,a[100005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
	a[0]=0,a[n+1]=0;
    for(int i=1;i<=n+1;i++) sum+=abs(a[i]-a[i-1]);
    for(int i=1;i<=n;i++)
	{
        int t1=abs(a[i+1]-a[i]);
        int t2=abs(a[i]-a[i-1]);
        int t3=abs(a[i+1]-a[i-1]);
        cout<<sum-t1-t2+t3<<endl;
    }
    return 0;
}