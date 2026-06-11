#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define PII pair<ll,ll>
#define VI  vector<ll>
#define VB  vector<bool>
#define VC vector<char>
#define VVI vector<vector<ll>>
#define VVC vector<vector<char>>
#define VS  vector<string>
#define VP  vector<PII>
#define lf(i,a,b) for(ll i=a;i<=b;i++)
#define lr(i,a,b) for(ll i=a;i>=b;i--)
#define lfl(i,v) for(ll i=0;i<v.size();i++)
#define lrl(i,v) for(ll i=(ll)(v.size())-1;i>=0;i--)
#define chk2(a,b) cout<<"check :  "<<a<<" "<<b<<endl
#define chk3(a,b,c) cout<<"check :  "<<a<<" "<<b<<" "<<c<<endl
#define chk4(a,b,c,d) cout<<"check :  "<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define chk5(a,b,c,d,e) cout<<"check :  "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl
#define l_b(v,k)  lower_bound(v.begin(),v.end(),k)-v.begin()
#define u_b(v,k)  upper_bound(v.begin(),v.end(),k)-v.begin()
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define p_b push_back
#define p_f push_front
#define m_p make_pair
#define fir first
#define sec second
#define sz size()
ll n,m,k;
VI v;
VI cmprs(VI &ht)
    {   VP vp(n);
        VI ans(n+1);
        lf(i,0,n-1)
        {   vp[i]=m_p(ht[i+1],i+1);
        }
        sort(vp);
        lf(i,1,n)
        {   ans[vp[i-1].sec]=i;
        }
        // cout<<endl;
        // lf(i,1,n)
        //     cout<<ans[i]<<" ";
        // cout<<endl;
        return ans;
    }

vector<ll>tree(800000,0);
ll qry(vector<ll>&tree,ll ti,ll fi,ll ls,ll str,ll end)
    {   ll mid=(ls+fi)/2;
        if(str>ls || end<fi || fi>ls)
            return 0;   
        if(str<=fi && ls<=end)
            return tree[ti];
        else 
            return max(qry(tree,ti*2,fi,mid,str,end),qry(tree,ti*2+1,mid+1,ls,str,end));
    }
void updt(vector<ll>&tree,ll ti,ll fi,ll ls,ll ind,ll val)
    {   if(ind>ls || ind<fi || ls<fi)   
            return ;
        else if(ind<=fi && ls<=ind)
        {   tree[ti]+=val;
        }
        else
        {   ll mid=(ls+fi)/2;
            updt(tree,ti*2,fi,mid,ind,val);
            updt(tree,ti*2+1,mid+1,ls,ind,val);
            tree[ti]=max(tree[ti*2],tree[ti*2+1]);
        }
    }

int main() 
{   cin>>n;
    VI a=VI(n+1);
    VI ht=VI(n+1);
    lf(i,1,n)
    {   cin>>ht[i];
    }
    ht=cmprs(ht);
    lf(i,1,n)
        cin>>a[i];
    VI dp(n+1,0);
    lf(i,1,n)
    {   dp[i]=a[i];
        ll sum=qry(tree,1,0,n+1,1,ht[i]-1);
        dp[i]=max(dp[i],a[i]+sum);
        updt(tree,1,0,n+1,ht[i],dp[i]);
    }

    ll maxi=0;
    lf(i,1,n)
    {    maxi=max(maxi,dp[i]);}//cout<<dp[i]<<" ";}
    cout<<maxi<<endl;
}