#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MOD 1000000007
#define pb push_back
int query(vector<int>&BIT,int idx)
{
    int ans=0;
    while(idx)
    {
        ans=max(ans,BIT[idx]);
        idx-=(idx&-idx);
    }
    return ans;
}
void update(vector<int>&BIT,int idx, int val)
{
    while(idx<BIT.size())
    {
        BIT[idx]=max(BIT[idx],val);
        idx+=(idx&-idx);
    }
    return ;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> BIT(N+1,0);
    vector<int> h(N);
    vector<int>A(N);
    for(int i=0;i<N;i++)cin>>h[i];
    for(int i=0;i<N;i++)cin>>A[i];
    
    for(int i=0;i<N;i++)
    {
        int k=query(BIT,h[i]-1);
            update(BIT,h[i],A[i]+k);
        
    }
    cout<<query(BIT,N);
    
    return 0;
}