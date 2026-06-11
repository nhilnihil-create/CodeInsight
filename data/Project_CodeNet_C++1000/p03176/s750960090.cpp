#include <bits/stdc++.h>
#define int long long int
const int N = 1e6;
using namespace std;
int tree[2*N];
int hei[N];
int val[N];
signed main()
{
    int n,t;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        hei[i]=t-1;
    }
    
    for(int i=0;i<n;i++)
    cin>>val[i];
    
    for(int i=0;i<2*n;i++)
    tree[i] = 0;

    for(int i=0;i<n;i++)
    {
        int l = n;
        int r = n+hei[i];
        int best=0;
        for(;l<r;l>>=1,r>>=1)
        {
            if((l&1)==1) 
            best = max(best,tree[l++]);
            if((r&1)==1)
            best = max(best,tree[--r]);
        }
        tree[n+hei[i]] = max(tree[n+hei[i]],best + val[i]);
        r = n+hei[i];

        for(;r>1;r>>=1)
        {
            tree[r>>1] = max(tree[r],tree[r^1]);
        }
    }

    //for(int i=1;i<2*n;i++)
   // cout<<tree[i]<<endl;
    cout<<tree[1];
    return 0;
}
