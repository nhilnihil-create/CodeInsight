//agrawal117
//chahatagrawal117
#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
typedef long long int ll;
using namespace std;
#define MAX 100005
bool comp(vector<ll> v1, vector<ll> v2)
{
    if(v1[0]>v2[0]) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k; cin>>n>>k;
    vector<vector<ll>> v(n);
    for(int i=1;i<=n;i++){
        ll a,x; cin>>a>>x;
        a--;
        v[a].push_back(x);
    }
    for(int i=0;i<n;i++){
        if(v[i].size()==0) v[i].push_back(INT_MIN);
        else {
            sort(v[i].rbegin(),v[i].rend());
        }
    }
    sort(v.begin(),v.end(),comp);
    priority_queue<ll> pq;
    ll ans=k*k;
    ll sum=0;
    for(int i=0;i<k;i++){
        sum+=v[i][0];
        for(int j=1;j<v[i].size();j++) pq.push(v[i][j]);
    }
    ans=ans+sum;
    
    for(int i=k;i<n;i++){
        for(int j=0;j<v[i].size();j++) pq.push(v[i][j]);
    }
    for(int i=k-1;i>=1;i--)
    {
        ll a=v[i][0]; ll b=pq.top();
        if(a>=b) break;
        pq.pop();
        sum-=a; sum+=b;
        pq.push(a);
        ans=max(ans,sum+(ll)i*i);
    }
    cout<<ans<<endl;
    
}