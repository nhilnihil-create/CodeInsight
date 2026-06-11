#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,i,num=1;
    cin>>n>>k;
    for(i=1;i<=n;i++){
       if(num*2<=num+k) num=num*2;
       else num=num+k;

    }cout<<num;
    return 0;
}
