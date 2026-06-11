#include <bits/stdc++.h>

using namespace std;

#define int long long
#define N 100005



int32_t main()
{
    int l;
    cin>>l;

    vector < pair < pair < int , int > , int > > ans;

    int n = 1;
    int cur = 2, sum = 0;
    for(int i=1;i<=21;i++)
    {
        sum=cur;
        if( (cur*2) > l)
        {
            n = i;
            break;
        }
        cur*=2;
    }
    cur = 1;
    int pp = 1;
    n++;

    for(int i=1;i<=n-1;i++)
    {
        if(l==0)
            break;
        if(l%2!=0)
        {
            l--;
            ans.push_back({{i, n}, sum}); 
            sum+=cur;  
        }
        cur*=2;
        ans.push_back({{i, i+1}, pp});
        ans.push_back({{i, i+1}, 0});
        pp*=2;
        l/=2;
    }

    cout<<n<<" "<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
    }
    return 0;
}