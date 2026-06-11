#include<bits/stdc++.h>
using namespace std;
int main()
{
    int j,i,k,s[6];
    bool ans=false;
    for(i=0;i<5;i++)
        cin>>s[i];
    cin>>k;
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(abs(s[i]-s[j])>k)
            {
                ans=true;
                break;
            }
        }
        if(ans)
            break;
    }
    cout<<(ans?":(":"Yay!")<<endl;
}
