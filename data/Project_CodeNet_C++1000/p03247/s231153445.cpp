#include <bits/stdc++.h>
using namespace std;

long long n,x[1005],y[1005],p,sd[35];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cerr.tie(0);

    cin>>n;
    cin>>x[0]>>y[0];
    p=abs(x[0]+y[0])%2;
    int ind=0;
    for(int i=1;i<n;i++)
    {
        cin>>x[i]>>y[i];
        if(abs(x[i]+y[i])%2!=p)
            ind=1;
    }
    if(ind)
    {
        cout<<-1<<endl;
        return 0;
    }
    sd[0]=1;
    for(int i=1;i<35;i++)
        sd[i]=sd[i-1]*2;

    if(p==0)
    {
        cout<<32<<endl;
        cout<<1<<" ";
        for(int i=0;i<=30;i++)
            cout<<sd[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            y[i]--;
            //cout<<x[i]<<y[i]<<endl;
            int br=31;
            vector<char> slova;
            while(br)
            {
                if(llabs(x[i]-sd[br-1])+llabs(y[i])<=sd[br-1]-1)
                {
                    slova.push_back('R');
                    x[i]-=sd[br-1];
                }
                else if(llabs(x[i]+sd[br-1])+llabs(y[i])<=sd[br-1]-1)
                {
                    slova.push_back('L');
                    x[i]+=sd[br-1];
                }
                else if(llabs(y[i]+sd[br-1])+llabs(x[i])<=sd[br-1]-1)
                {
                    slova.push_back('D');
                    y[i]+=sd[br-1];
                }
                else if(llabs(y[i]-sd[br-1])+llabs(x[i])<=sd[br-1]-1)
                {
                    slova.push_back('U');
                    y[i]-=sd[br-1];
                }
                br--;
            }
            //cout<<x[i]<<y[i]<<endl;
            cout<<'U';
            reverse(slova.begin(),slova.end());
            for(int i=0;i<slova.size();i++)
                cout<<slova[i];
            cout<<endl;
        }
    }
    else
    {
        cout<<31<<endl;
        for(int i=0;i<=30;i++)
            cout<<sd[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            int br=31;
            vector<char> slova;
            while(br)
            {
                if(llabs(x[i]-sd[br-1])+llabs(y[i])<=sd[br-1]-1)
                {
                    slova.push_back('R');
                    x[i]-=sd[br-1];
                }
                else if(llabs(x[i]+sd[br-1])+llabs(y[i])<=sd[br-1]-1)
                {
                    slova.push_back('L');
                    x[i]+=sd[br-1];
                }
                else if(llabs(y[i]+sd[br-1])+llabs(x[i])<=sd[br-1]-1)
                {
                    slova.push_back('D');
                    y[i]+=sd[br-1];
                }
                else if(llabs(y[i]-sd[br-1])+llabs(x[i])<=sd[br-1]-1)
                {
                    slova.push_back('U');
                    y[i]-=sd[br-1];
                }
                br--;
            }
            reverse(slova.begin(),slova.end());
            for(int i=0;i<slova.size();i++)
                cout<<slova[i];
            cout<<endl;
        }
    }

}
