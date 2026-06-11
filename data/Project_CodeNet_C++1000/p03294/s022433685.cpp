#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,sum=0;
    cin>>n;
    int a[n+5]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    cout<<sum-n<<endl;
    return 0;
}

