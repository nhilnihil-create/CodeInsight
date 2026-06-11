#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define DL double
#define MLL map<LL,LL>::iterator
#define MSL map<string,L>::iterator
#define MLS map<LL,string>::iterator
#define MSS map<string,string>::iterator
#define MCL map<char,LL>::iterator
#define SL set<LL>::iterator
#define SS set<string>::iterator
#define VL V<LL>::iterator
#define G getline
#define SZ size()
#define IN insert
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM emptm()
#define V vector
#define Q queue
#define DQ deque
#define PQ prioritm_queue
#define ST stack
#define FI first
#define MAX 1e18
#define MIN -1e18
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
V<LL>v,w,uu,vv;
map<LL,LL>u;
void Y()
{
    cout<<"YES"<<endl;
}
void N()
{
    cout<<"NO"<<endl;
}
int main()
{
    FAST;
    LL n,m,i,j,k,p,q,o,l,s,t,z=0,r;
    string a,b,c;
    cin>>n>>m>>j;
    for(i=0; i<n; i++)
    {
        cin>>o;
        v.PSB(o);
    }
    for(i=0; i<m; i++)
    {
        cin>>o;
        w.PSB(o);
    }
    sort(v.B,v.E);
    sort(w.B,w.E);
    k=MAX;
    for(i=0; i<j; i++)
    {
        cin>>o;
        uu.PSB(o);
    }
    for(i=0; i<j; i++)
    {
        o=uu[i];
        if(o>=v[v.SZ-1])
        {
            l=(abs(o-v[v.SZ-1]));
            o=v[v.SZ-1];
            if(o>=w[w.SZ-1])
            {
                l+=abs(o-w[w.SZ-1]);
            }
            else
            {
                VL it=lower_bound(w.B,w.E,o);
                s=it-w.B;
                s=abs(w[s]-o);
                t=MAX;
                if(it-w.B!=0)
                {
                    t=it-w.B;
                    t--;
                    t=abs(w[t]-o);
                }
                l+=min(s,t);
            }
            k=l;
        }
        else
        {
            VL it=lower_bound(v.B,v.E,o);
            s=it-v.B;
            LL oo=v[s];
            s=abs(v[s]-o);
            if(oo>=w[w.SZ-1])
            {
                s+=abs(oo-w[w.SZ-1]);
            }
            else
            {
                VL it=lower_bound(w.B,w.E,oo);
                p=it-w.B;
                p=abs(w[p]-oo);
                q=MAX;
                if(it-w.B!=0)
                {
                    q=it-w.B;
                    q--;
                    q=abs(w[q]-oo);
                }
                s+=min(p,q);
            }
            t=MAX;
            if(it-v.B!=0)
            {
                t=it-v.B;
                t--;
                LL oo=v[t];
                t=abs(v[t]-o);
                if(oo>=w[w.SZ-1])
                {
                    t+=abs(oo-w[w.SZ-1]);
                }
                else
                {
                    VL it=lower_bound(w.B,w.E,oo);
                    p=it-w.B;
                    p=abs(w[p]-oo);
                    q=MAX;
                    if(it-w.B!=0)
                    {
                        q=it-w.B;
                        q--;
                        q=abs(w[q]-oo);
                    }
                    t+=min(p,q);
                }
            }
            k=min(t,s);
        }
        vv.PSB(k);
    }
    swap(v,w);
    for(i=0; i<j; i++)
    {
        o=uu[i];
        if(o>=v[v.SZ-1])
        {
            l=abs(o-v[v.SZ-1]);
            o=v[v.SZ-1];
            if(o>=w[w.SZ-1])
            {
                l+=abs(o-w[w.SZ-1]);
            }
            else
            {
                VL it=lower_bound(w.B,w.E,o);
                s=it-w.B;
                s=abs(w[s]-o);
                t=MAX;
                if(it-w.B!=0)
                {
                    t=it-w.B;
                    t--;
                    t=abs(w[t]-o);
                }
                l+=min(s,t);
            }
            k=l;
        }
        else
        {
            VL it=lower_bound(v.B,v.E,o);
            s=it-v.B;
            LL oo=v[s];
            s=abs(v[s]-o);
            if(oo>=w[w.SZ-1])
            {
                s+=abs(oo-w[w.SZ-1]);
            }
            else
            {
                VL it=lower_bound(w.B,w.E,oo);
                p=it-w.B;
                p=abs(w[p]-oo);
                q=MAX;
                if(it-w.B!=0)
                {
                    q=it-w.B;
                    q--;
                    q=abs(w[q]-oo);
                }
                s+=min(p,q);
            }
            t=MAX;
            if(it-v.B!=0)
            {
                t=it-v.B;
                t--;
                LL oo=v[t];
                t=abs(v[t]-o);
                if(oo>=w[w.SZ-1])
                {
                    t+=abs(oo-w[w.SZ-1]);
                }
                else
                {
                    VL it=lower_bound(w.B,w.E,oo);
                    p=it-w.B;
                    p=abs(w[p]-oo);
                    q=MAX;
                    if(it-w.B!=0)
                    {
                        q=it-w.B;
                        q--;
                        q=abs(w[q]-oo);
                    }
                    t+=min(p,q);
                }
            }
            k=min(t,s);
        }
        vv[i]=min(vv[i],k);
    }
    for(i=0;i<j;i++)
    {
        cout<<vv[i]<<endl;
    }
    return 0;
}
