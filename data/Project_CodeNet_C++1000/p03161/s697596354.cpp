#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    #ifdef LOCAL_EXEC
    #else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif // LOCAL_EXEC
    long long int n,k,i,j,x;
    cin>>n>>k;
    long long int A[n],result[n]={0};
    for(i=0;i<n;i++){
        cin>>A[i];
    }
    result[0]=0;
    for(i=1;i<n;i++){
        x=INT_MAX;
        for(j=1;j<=k;j++){
            if(i-j<0)
            break;
            x=min(x,result[i-j]+abs(A[i]-A[i-j]));
        }
        result[i]=x;
    }
    cout<<result[n-1];
    return 0;
}
