#include <iostream>

using namespace std;
int n,m,stanga,st,dr,mid,sol,dreapta;
char a[200005];
struct spell
{
    char l,d;
};
spell v[200005];
bool iese_prin_dreapta(int poz)
{
    int i;
    for(i=1;i<=m;i++)
    {
        if(v[i].l==a[poz])
        {
            if(v[i].d=='L')
            {
                poz--;
            }
            else
            {
                poz++;
            }
        }
        if(poz==0)
        {
            return 0;
        }
        else
        {
            if(poz==n+1)
            {
                return 1;
            }
        }
    }
    return (poz==n+1);
}
bool iese_prin_stanga(int poz)
{
    int i;
    for(i=1;i<=m;i++)
    {
        if(v[i].l==a[poz])
        {
            if(v[i].d=='L')
            {
                poz--;
            }
            else
            {
                poz++;
            }
        }
        if(poz==0)
        {
            return 1;
        }
        else
        {
            if(poz==n+1)
            {
                return 0;
            }
        }
    }
    return (poz==0);
}
int main()
{
    int i;
    cin>>n>>m;
    cin>>(a+1);
    for(i=1;i<=m;i++)
    {
        cin>>v[i].l>>v[i].d;
    }
    st=1;
    dr=n;
    stanga=0;
    while(st<=dr)
    {
        mid=(st+dr)/2;
        if(iese_prin_dreapta(mid))
        {
            stanga=mid;
            dr=mid-1;
        }
        else
        {
            st=mid+1;
        }
    }
    st=1;
    dr=n;
    dreapta=n+1;
    while(st<=dr)
    {
        mid=(st+dr)/2;
        if(iese_prin_stanga(mid))
        {
            dreapta=mid;
            st=mid+1;
        }
        else
        {
            dr=mid-1;
        }
    }
    if(stanga!=0)
    {
        sol+=n-stanga+1;
    }
    if(dreapta!=n+1)
    {
        sol+=dreapta;
    }
    cout<<n-sol;
    return 0;
}
