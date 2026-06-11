#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c;
    vector<int>v;
    cin>>n>>m>>c;
    int t=n,g,r=m,x=c,p,i=0,j=0;
    while(r--)
    {
        cin>>g;
        v.push_back(g);
    }
    while(t--)
    {
        while(i<m)
        {
            cin>>p;
            x=x+(v[i]*p);
            i++;
        }
        //cout<<x<<endl;
        if(x>0)
        {
            //cout<<x<<endl;
            j++;
        }
        i=0;
        x=c;
    }
    cout<<j<<endl;
    return 0;
}
