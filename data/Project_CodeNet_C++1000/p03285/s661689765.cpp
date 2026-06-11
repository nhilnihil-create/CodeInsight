#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    bool ans;
    cin>>n;
    if(n%4==0||n%7==0||n%11==0)
        cout<<"Yes"<<endl;
    else
    {
        for(i=0; ;i++)
        {
            n-=11;
            if((n%4==0||n%7==0)&&n>=0)
            {
                ans=true;
                break;
            }
            if(n<0)
            {
                ans=false;
                break;
            }
        }
        if(ans)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
