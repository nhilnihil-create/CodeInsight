#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;

int main()
{
    /*ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    //freopen("output.txt","w+",stdout);
    //freopen("input.txt","r+",stdin);
    int n,k,idx1,ans=INF;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i],
        idx1=(v[i]==1?i:idx1);
    int l=max(0,idx1-k+1),r=min(n-1,l+k-1);
    for(;l<=idx1&&r<n;l++,r++)
        ans=min(ans,1+(int)ceil((double)l/(k-1))+(int)ceil((double)(n-1-r)/(k-1)));
    cout<<ans;
    return 0;
}
/* 3 3
   1 2 3
*/
