#include<bits/stdc++.h>
using namespace std;
bool comp(pair<long long int,long long int>a,pair<long long int,long long int>b)
{
    if(a.first==b.first)
    {
        if(a.second<=b.second)
        return true;
        else
        return false;
    }
    if(a.first>b.first)
    return true;
    else return false;
}
long long int gcd(long long int bdda,long long int chota)
{
    if(chota==0)
        return bdda;
    return gcd(chota,bdda%chota);
}
void solve()
{
    long long int n;cin>>n;
    priority_queue<long long int>pq;
    for(long long int j=0;j<n;j++){long long int num;cin>>num;pq.push(num);};
    long long int a=0,b=0,i=0;
    while(pq.size()>0)
    {
        if(i%2==0)
        a+=pq.top();
        else
        b+=pq.top();
        pq.pop();
        i++;
    }
    cout<<abs(a-b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;

    //cin>>t;
    while(t--)
    {
        solve();
    }
}
