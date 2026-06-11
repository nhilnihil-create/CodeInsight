#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>>pq;

int main()
{
    int n,ans;
    int t1,t2;
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        cin >> t1;
        pq.push(t1);
    }

    ans=pq.top();
    while((pq.size())>1 && ans!=1)
    {
        t1=pq.top();
        pq.pop();
        t2=pq.top();
        pq.pop();
        pq.push(t1);
        t2=(t2%t1);
        if(t2)
        {
            ans=min(ans,t2);
            pq.push(t2);
        }
    }

    cout << min(ans,pq.top()) << "\n";
    
    return 0;
}