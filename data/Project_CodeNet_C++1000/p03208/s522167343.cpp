#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    long int n,k;
    cin>>n>>k;
    vector<long int> a(n);
    for(long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    long int k1=INT_MAX;
    for(long int i=0;i<=n-k;i++)
    {
        long int k2=a[i+k-1]-a[i];
        if(k2<k1)
        {
            k1=k2;
        }
    }
    cout<<k1<<endl;
    return 0;
}
