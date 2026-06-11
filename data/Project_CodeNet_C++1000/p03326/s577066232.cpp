#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a, long long b)
{
    return a>b;
}
int main()
{
    int n,m;
    cin>>n>>m;
    long long mx = -(99999999);
    long long arr[9999][3];
    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++)cin>>arr[i][j];
    }

    for(int i=0; i<8; i++){
        vector<long long>v;
        for(int j=1; j<=n; j++){

            long long sum=0;
            for(int k=0; k<3; k++){
                if((i/(1<<k))%2==0)sum+=arr[j][k];
                else sum-=arr[j][k];
            }
           v.push_back(sum);
        }
        sort(v.begin(),v.end(),cmp);
        long long ans=0;
        for(int i=0; i<m; i++){
            ans+=v[i];
        }
        mx = max(mx, ans);
    }
    cout<<mx<<endl;
}
