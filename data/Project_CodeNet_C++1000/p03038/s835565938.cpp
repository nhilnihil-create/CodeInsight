
#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    ios;
    int n,m;
    cin>>n>>m;
    int a[n];
    priority_queue<pair<int,int> >s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s.push(mp(a[i],1));
    }
    vector<int>b(m),c(m);
    for(int i=0;i<m;i++)
    {
        cin>>b[i]>>c[i];
        s.push(mp(c[i],b[i]));
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
         priority_queue<pair<int,int> >::value_type it;
        it=s.top();
         s.pop();
         ans+=it.first;
         if(it.second>1)
         {
             it.second--;
             s.push(it);
         }
    }
    cout<<ans<<endl;


}






































