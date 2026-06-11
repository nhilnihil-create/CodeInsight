#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,x,y,poc;
string s;
vector<ll> goredole,levodesno;
unordered_set<ll> dpx[16005],dpy[16005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>s>>x>>y;
    n=s.size();

    ll cnt=0;
    for(ll i=0;i<n;i++)
        if(s[i]=='F')
            cnt++;
        else
        {
            poc=cnt;
            break;
        }
    if(cnt==n)
    {
        x-=n;
        if(x==0&&y==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        return 0;
    }
    x-=poc;
    ll br=0,smer=1;
    for(ll i=cnt;i<n;i++)
    {
        if(s[i]=='F')
            br++;
        else
        {
            if(br>0)
            {
                if(smer==1)
                    levodesno.push_back(br);
                else
                    goredole.push_back(br);
                br=0;
            }
            smer*=-1;
        }
    }
    if(br>0)
    {
        if(smer==1)
            levodesno.push_back(br);
        else
            goredole.push_back(br);
        br==0;
    }
    /*ll ind1=2,ind2=2;
    if(goredole.size()==0)
        if(y==0)
            ind1=1;
        else
            ind1=0;
    if(levodesno.size()==0)
        if(x==0)
            ind2=1;
        else
            ind2=0;
    */
    dpx[0].insert(0); dpy[0].insert(0);
    for(ll i=0;i<levodesno.size();i++)
    {
        for(ll j=-n;j<=n;j++)
            if(dpx[i].count(j+levodesno[i])||dpx[i].count(j-levodesno[i]))
                dpx[i+1].insert(j);
    }
    for(ll i=0;i<goredole.size();i++)
    {
        for(ll j=-n;j<=n;j++)
            if(dpy[i].count(j+goredole[i])||dpy[i].count(j-goredole[i]))
                dpy[i+1].insert(j);
    }
    /*if(ind1!=2||ind2!=2)
    {
        if(ind1==1&&ind2==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        return 0;
    }*/
    
    if(dpx[levodesno.size()].count(x)&&dpy[goredole.size()].count(y))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
