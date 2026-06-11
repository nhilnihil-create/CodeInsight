#include <bits/stdc++.h>
using namespace std;
map<long long,long long int> mp;
long long mulmod(long long a,long long b,long long c){
        long long x = 0,y=a%c;
        while(b > 0) {
                if(b%2 == 1) {
                        x = (x+y)%c;
                }
                y = (y*2)%c;
                b /= 2;
        }
        return x%c;
}
long long int modulo_exp(long long int a,long long int b,long long int c)
{
        long long x=1,y=a;
        while(b > 0) {
                if(b%2 == 1) {
                        x = mulmod(x,y,c);
                }
                y = mulmod(y,y,c);
                b /= 2;
        }
        return x%c;
}
bool Miller(long long p,int iteration){
        if(p<2) {
                return false;
        }
        if(p!=2 && p%2==0) {
                return false;
        }
        long long s=p-1;
        while(s%2==0) {
                s/=2;
        }
        for(int i=0; i<iteration; i++) {
                long long a=rand()%(p-1)+1,temp=s;
                long long mod=modulo_exp(a,temp,p);
                while(temp!=p-1 && mod!=1 && mod!=p-1) {
                        mod=mulmod(mod,mod,p);
                        temp *= 2;
                }
                if(mod!=p-1 && temp%2==0) {
                        return false;
                }
        }
        return true;
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long n,p;
        cin>>n>>p;
        vector< long long > div;
        for(long long i=2; i*i<=p; i++)
        {
                if((p%i)==0)
                {
                        if(i!=(p/i))
                        {
                                div.push_back(i);
                                div.push_back((p/i));
                        }
                        else
                        {
                                div.push_back(i);
                        }
                }
        }
        for(int i=0; i<div.size(); i++)
        {
                if(Miller(div[i],18))
                {
                        long long d=div[i],nn=p;
                        while(nn%d==0)
                        {
                                mp[d]++;
                                nn=nn/d;
                        }
                }
        }
        long long pp=1;
        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
                if( (it->second)>=n )
                {
                        long long int cc=(it->second)/n;
                        while(cc--)
                        {
                                pp=pp*(long long)(it->first);
                        }
                }
        }
        cout<<pp<<endl;
        return 0;
}
