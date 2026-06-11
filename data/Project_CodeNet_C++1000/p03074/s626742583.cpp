#include<bits/stdc++.h>
using namespace std;
vector<pair<int ,int> >v;
int main()
{
    long long t,k,n,c,x,p,in,fn,flag;
    string s;
    cin>>n>>k;
    cin>>s;
    in=0;
    flag=0;
    //n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            flag=1;
            if(i==n-1)
            {
                //cout<<in<<" "<<i<<endl;
            v.push_back({in,i});

            }
            continue;
        }
        else
        {
            if(!flag)

            {
                in=i+1;
                continue;
            }
            else{
                //cout<<in<<" "<<i-1<<endl;
            v.push_back({in,i-1});
            flag=0;
            in=i+1;
            }

        }
    }
    long long  ip,next,sz=v.size(),ans=INT_MIN;
    if(sz==0)
    {
        cout<<n;
        return 0;
    }

    if(count(s.begin(),s.end(),'1')==n)
    {
        cout<<n;
        return 0;
    }
    if(v[0].first!=0)
    {

        fn=v[k-1].second;
        ans=fn+1;
        //cout<<0<<" "<<fn<<" "<<ans<<endl;
    }

    for(int i=0;i<sz-k;i++)
    {
        in=v[i].first;
        fn=v[i+k].second;
        //cout<<in<<" "<<fn<<" "<<fn-in<<endl;
        ans=max(ans,(fn-in+1));
    }
    if(v[sz-1].second!=n-1)
    {
        in=v[sz-k].first;
        fn=n;
        //cout<<in<<" "<<fn<<" "<<fn-in<<endl;
        ans=max(ans,(fn-in));
    }

    if(k>sz )
    {
        cout<<n;
        return 0;
    }



    cout<<ans;



}


