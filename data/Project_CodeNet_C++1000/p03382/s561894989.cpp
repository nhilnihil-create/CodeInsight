#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n,num[100005],i,j,ai=0,aj=0;
    cin>>n;
    for(i=1;i<=n;i++){scanf("%d",&num[i]);ai=max(ai,num[i]);}
    for(i=1;i<=n;i++){
        if(fabs((double)aj-(double)ai/2)>fabs((double)num[i]-(double)ai/2))
            aj=num[i];
    }
   cout<<ai<<' '<<aj<<endl;

    return 0;

}