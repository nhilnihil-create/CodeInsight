//agrawal117
//chahatagrawal117
#include<bits/stdc++.h>
#define mod 1000000007
#define endl '\n'
typedef long long int ll ;
using namespace std;
#define MAX 100003
bool check(vector<int> v)
{
    for(int i=0;i<v.size();i++){
        if(v[i]>1) return false;
    }
    return true;
}
int main()
{
    ll n; cin>>n;
    if(n==1)  { cout<<1<<endl; return 0; }
    bitset<22> dp[n+2];
    for(int i=1;i<=n;i++){
        ll a; cin>>a;
        bitset<22> bs(a);
        dp[i]=bs;
    }
    int start=1;
    int end=2;
    vector<int> v(22,0);
    ll ans=0;
    for(int i=0;i<22;i++) v[i]+=dp[1][i]+dp[2][i];
    while(start<=n){
        while(end<=n){
            int flag=0;
            if(!check(v)) break;
            end++;
            for(int i=0;i<22;i++){
                v[i]+=dp[end][i];
            }
        }
        // cout<<start<<" "<<end<<endl;
        ans+=end-start;
        for(int i=0;i<22;i++){
            v[i]-=dp[start][i];
        }
        // for(int i=0;i<22;i++) cout<<v[i]<<" ";
        // cout<<endl;
        start++;
    }
    cout<<ans<<endl;
    
    
}