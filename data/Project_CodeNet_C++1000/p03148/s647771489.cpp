#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

signed main()
{
    int K,N;
    cin>>N>>K;

    vector<int> memo[100000];
    for(int i=0;i<N;i++)
    {
        int t,d;
        cin>>t>>d;
        t--;
        memo[t].emplace_back(d);
    }

    vector<ll> q1,q2;
    for(int i=0;i<N;i++)
    {
        sort(memo[i].rbegin(),memo[i].rend());
        if(memo[i].size())
        {
            q1.emplace_back(memo[i][0]);
            for(int j=1;j<memo[i].size();j++)q2.emplace_back(memo[i][j]);
        }
    }
    sort(rbegin(q1),rend(q1));
    sort(rbegin(q2),rend(q2));
    for(int i=1;i<q2.size();i++)q2[i]+=q2[i-1];
    
    ll ret=0,make=0;
    for(int i=0;i<K&&i<q1.size();i++)
    {
        make+=q1[i];
        ll rest=K-i-1;
        if(rest<=q2.size())
        {
            ll odd=rest<=0?0:q2[rest-1];

            ll tmp=make+odd+1LL*(i+1)*(i+1);
            if(ret<tmp)ret=tmp;
        }
    }

    cout<<ret;
    return 0;
}