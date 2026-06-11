#include <bits/stdc++.h>
using namespace std;

#define INF 1000100000

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;
    cin>>n>>k;

    vector<int> h(n);

    for(int i=0;i<n;i++)cin>>h[i];

    sort(h.begin(),h.end());

    int mi=INF;

    for(int i=0;i<n-k+1;i++)
    {
        mi=min(mi,h[i+k-1]-h[i]);
    }

    cout<<mi<<"\n";

    return 0;
}
