#include <iostream>
#include <vector>;
using namespace std;
int main()
{
    int a[10],N,maxi,j,i,sum;
    cin>>N;
    for(i=1;i<=N;i++){
        cin>>j;
        a[i-1]=j;
    }

    maxi=a[0];
    sum=a[0];
    for(i=1;i<N;i++){
        sum+=a[i];
        if(a[i]>=a[i-1])
            maxi=a[i];
        else
            a[i]=a[i-1];

    }
    if(maxi<(sum-maxi)){
        cout<<"Yes";
    }
    else
        cout<<"No";

}
