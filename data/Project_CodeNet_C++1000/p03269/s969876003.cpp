#include <bits/stdc++.h>
using namespace std;

long long l,sd[45],r,br,cnt;
vector<int> poz;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cerr.tie(0);

    cin>>l;
    sd[0]=1;
    int ind=1;
    for(int i=1;i<45;i++)
    {
        sd[i]=sd[i-1]*2;
        if(sd[i]>l&&ind)
        {
            r=i-1;
            ind=0;
        }
    }
    for(int i=0;i<r;i++)
        if((1<<i)&l)
            br++;
    cout<<r+1<<" "<<2*r+br<<endl;
    for(int i=1;i<r+1;i++)
    {
        cout<<i<<" "<<i+1<<" "<<0<<endl;
        cout<<i<<" "<<i+1<<" "<<sd[i-1]<<endl;
    }
    cnt=1<<r;
    for(int i=0;i<r;i++)
    {
        if((1<<i)&l)
        {
            cout<<i+1<<" "<<r+1<<" "<<cnt<<endl;
            cnt+=(1<<i);
        }
    }

    return 0;
}
