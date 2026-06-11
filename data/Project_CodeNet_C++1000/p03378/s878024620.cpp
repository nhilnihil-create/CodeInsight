#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,x,a[102],sum1=0,sum2=0;
    cin>>n>>m>>x;
    a[0]=x;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a,a+m+1);
    for(int i=0;i<=m;i++){
        if(a[i]==x) break;

        sum1+=1;
    }
    sum2=m-sum1;
    cout<<min(sum1,sum2);
    return 0;
}
