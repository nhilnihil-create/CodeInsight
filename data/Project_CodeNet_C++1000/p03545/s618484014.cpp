#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;cin>>s;

    for(int i=0;i<8;i++)
    {
        int ans=s[0]-'0';
        ss makeans;
        makeans<<s[0]-'0';
        for(int j=0,k=i;j<3;j++,k=k>>1)
        {
            if(k%2)
            {
                ans+=s[j+1]-'0';
                makeans<<"+"<<s[j+1]-'0';
            }
            else
            {
                ans-=s[j+1]-'0';
                makeans<<"-"<<s[j+1]-'0';
            }            
        }
        makeans<<"=7";
        if(ans==7)
        {
            cout<<makeans.str()<<"\n";
            break;
        }
    }

    return 0;
}
