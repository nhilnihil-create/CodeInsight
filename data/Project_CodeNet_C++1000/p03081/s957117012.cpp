#include <iostream>

using namespace std;
char s[200001],c,d;
struct querys
{
    char c;
    int dir;
} v[200001];
int n,q,i,p,u,m,solst,soldr,mm;
int main()
{
    cin>>n>>q;
    cin>>s;
    for(i=1; i<=q; i++)
    {
        cin>>c>>d;
        v[i].c=c;
        if(d=='L')v[i].dir = 0;
        else v[i].dir = 1;
    }
    int p=1,u=n;
    while(p <= u)
    {
        m=(p+u)/2;
        mm=m;
        for(i=1; i<=q; i++)
        {
            if(1<=m&&m<=n)
            {
                if(v[i].c==s[m-1])
                {
                    if(v[i].dir==0)m--;
                    else m++;
                }
            }
            else i=q+1;
           // cout<<i<<" ";
        }



        if(m==0)
        {
            p=mm+1;
            solst=mm;
        }
        else u=mm-1;

    }

    p=1;
    u=n;
    while(p <= u)
    {
        m=(p+u)/2;
        mm=m;
        for(i=1; i<=q; i++)
        {
            if(1<=m&&m<=n)
            {
                if(v[i].c==s[m-1])
                {
                    if(v[i].dir==0)m--;
                    else m++;
                }
            }
            else i=q+1;

        }


        if(m==n+1)
        {
            u=mm-1;
            soldr=mm;
        }
        else p=mm+1;
        // cout<<p<<" "<<u<<" "<<m<<'\n';
    }
    if(solst==0)
    {
        cout<<soldr-1<<'\n';
    }
    else if(soldr==0)
    {
        cout<<n-solst<<'\n';
    }
    else if(solst>=soldr)cout<<0<<'\n';
    else cout<<soldr-solst-1<<'\n';
    return 0;
}
