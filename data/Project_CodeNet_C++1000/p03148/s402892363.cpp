#include<bits/stdc++.h>
using namespace std;
vector<long long>v,vc;
multiset<pair<long long,long long> >st,stt;
multiset<pair<long long,long long> >::iterator it,jt;
long long vis[100005];
int main()
{
    long long a,b,c,d,i,j,n,k,tm,mx=0,f,g=0,ans;
    cin>>n>>k;
    for(i=0; i<n; i++)
    {
        cin>>a>>b;
        v.push_back(b);
        vc.push_back(a);
        st.insert({-1*b,a});

    }
    a=0;
    f=0;
    g=0;
    while(a<k)
    {
        it=st.begin();
        d=it->second;
        f=it->first;
        if(!vis[d])
        {
            vis[d]=1;
            mx+=-1*f;
            g++;
        }
        else
        {
            mx+=-1*f;
            stt.insert({-1*f,d});

        }
        a++;
        st.erase(it);
    }
    ans=mx+g*g;
    it=st.begin();
    while(it!=st.end()){
        d=it->second;
        f=it->first;
        if(!vis[d]&&stt.size()){
            jt=stt.begin();
            c=jt->first;
            mx-=c;
            stt.erase(jt);
            mx+=-1*f;
            g++;
            vis[d]=1;
        }
        it++;
        ans=max(ans,g*g+mx);
    }
    cout<<ans<<'\n';


    return 0;



}
