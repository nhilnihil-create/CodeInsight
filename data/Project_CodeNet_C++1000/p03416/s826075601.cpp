#include<bits/stdc++.h>
#define mod 1000000007
#define int long long int
#define phi 1.6180339
#define rep(i,n) for(auto i=0;i<(n);i++)
#define endl "\n"
#define For(i,a,b) for(auto i=(a);i<(b);i++)
#define op1 cin.tie(NULL)
#define op2 cout.tie(NULL)
#define op3 std::ios_base::sync_with_stdio(false)
#define MAXX 1000001
using namespace std;
vector<int> arr(MAXX);
void trozen()
{
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=a;i<=b;i++)
    {
        int temp=i;
        int temp2=0;
        while(temp)
        {
            temp2=temp2*10+temp%10;
            temp/=10;
        }
        if(i==temp2)
            ans++;
    }
    cout<<ans<<endl;
}
int32_t main()
{
    op1;op2;op3;
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
    trozen();
    return 0;
}
