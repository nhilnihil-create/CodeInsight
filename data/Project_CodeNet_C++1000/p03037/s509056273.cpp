#include<iostream>
#include<queue>

using namespace std;

int main() 
{
    int N,M;
    cin>>N>>M;

    priority_queue<int>L;
    priority_queue<int,vector<int>,greater<int>>R;

    for (size_t i = 0; i < M; i++)
    {
        int l,r;
        cin>>l>>r;
        L.push(l);
        R.push(r);
    }
    
    int ans=0;
    for (size_t i = 1; i < N+1; i++)
    {
        if(i>=L.top()&&i<=R.top())
        {
            ++ans;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}