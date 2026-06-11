#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
const int M=200005;
int n,m,x,y,a[M],b[M],freq[30];
ll ans;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    for(int j=0;j<=29;j++){
        int t[M],k=1<<j;
        for(int i=0;i<n;i++)t[i]=b[i]%(2*k);
        sort(t,t+n);
        for(int i=0;i<n;i++){
            int x=a[i]%(2*k);
            int l=lower_bound(t,t+n,k-x)-t;
            int r=lower_bound(t,t+n,2*k-x)-t-1;
            if(l!=n&&x+t[l]<2*k)freq[j]+=r-l+1;
            l=lower_bound(t,t+n,3*k-x)-t;
            r=lower_bound(t,t+n,4*k-x)-t-1;
            if(l!=n)freq[j]+=r-l+1;
        }
        if(freq[j]&1)ans|=k;

    }
    cout<<ans;
    return 0;
}
