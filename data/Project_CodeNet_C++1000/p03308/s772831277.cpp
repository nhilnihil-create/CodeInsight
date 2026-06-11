#include<bits/stdc++.h>
#include<cmath>

using namespace std;

int main()
{
    int n,a[101],i,j,d[100001],k=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
           int diff=abs(a[i]-a[j]);
           d[k++]=diff;
        }
    }
   sort(d,d+k);
   cout<<d[k-1];
    return 0;
}
