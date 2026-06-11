#include <bits/stdc++.h>
using namespace std;

int N,K;
const int n=200010;
int cnt[n];

int main()
{
    cin>>N>>K;
    for (int i = 0; i < n; i++)
    {
        cnt[i] = 0;
    }
    
    for (int i = 0; i < N; i++)
    {
        int a;
        cin>>a;
        cnt[a]++;
    }

    sort(cnt,cnt+n);
    
    int ans=0;
    for (int i = 0; i < n-K; i++) 
    {
        ans+=cnt[i];
    }
    
    cout << ans << endl;
        
    return 0;
}
