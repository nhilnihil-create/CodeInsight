#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[5],k,i,j;
    for(i=0;i<5;i++)
        cin>>ara[i];
    cin>>k;
    int p=0;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
    {
        if(i==j) continue;
        if(abs(ara[i]-ara[j])>k)
            p=1;
    }
    if(p==0)
        cout<<"Yay!"<<endl;
    else
        cout<<":("<<endl;

    return 0;

}
