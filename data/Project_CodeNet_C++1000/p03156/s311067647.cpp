#include <bits/stdc++.h>
#define min(a,b) a<b? a:b

using namespace std;
int main()
{
    int n,A,B;
    cin>>n>>A>>B;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int la=0,lb=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=A)
            la++;
        else if(a[i]>A && a[i]<=B)
            lb++;
    }
    int minm=min(la,lb);
    minm=min(minm,a.size()-la-lb);
    cout<<minm<<endl;
    return 0;
}
