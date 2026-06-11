#include<bits/stdc++.h>
using namespace std;

int main()
{

    string m,n;
    cin>>m>>n;
    int i,k=0,j;

    for(i=0; i<m.size(); i++)
    {
        //  cout<<m<<endl;
        if(m==n)
        {
            cout<<"Yes"<<endl;
            k=1;
            break;
        }
        else
        {
            for(j=m.size()-1; j>=1; j--)
            {
                swap(m[j],m[j-1]);
            }
        }
    }
    if(k==0)
        cout<<"No"<<endl;
    return 0;
}
