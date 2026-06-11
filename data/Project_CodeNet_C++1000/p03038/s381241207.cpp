#include<bits/stdc++.h>
using namespace std;

int main()
{

        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld %lld",&n,&m);

        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a); v.push_back(a);
        }

        sort(v.begin(),v.end());

        priority_queue<long long>pq;

        for(i=1;i<=m;i++)
        {
            scanf("%lld %lld",&a,&b); if(mp[b]==0){  pq.push(b);  }

            mp[b]=mp[b]+a;

        }


        for(i=0;i<n;i++)
        {
            a=v[i]; b=-7;

            if(!pq.empty()){ b=pq.top();  }

            if(a>=b){  sum=sum+a;  }
            else
            {
                sum=sum+b; mp[b]--; if(mp[b]==0)pq.pop();
            }

        }


        printf("%lld\n",sum);





    return 0;
}



