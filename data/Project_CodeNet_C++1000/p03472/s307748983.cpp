#include<bits/stdc++.h>
using namespace std;



int32_t main()
{
    int n,h;
    cin>>n>>h;
    vector<int> a,b;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    sort(rbegin(a),rend(a));
    vector<int> power;
    int ans=0;
    for(auto i:b)
    if(i>=a[0])power.push_back(i);
    int i=0;
    sort(rbegin(power),rend(power));
    while(h>0)
    {
        
        if(i>=int(power.size()))
        {
            ans+=(h+a[0]-1)/a[0];
            cout<<ans<<endl;
            return 0;
        }
        else
        {
            h-=power[i];
            ans++;
            if(h<=0)
            {
             cout<<ans<<endl;
             return 0;
            }
            i++;
        }
    }
}