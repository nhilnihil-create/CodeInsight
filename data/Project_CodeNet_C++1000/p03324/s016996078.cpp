#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
using namespace std;
const long long INF=(long long)0x3f3f3f3f3f3f3f3f;
const int MOD=(int)1e9+7;

int main()
{
    /*ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    //freopen("output.txt","w+",stdout);
    //freopen("input.txt","r+",stdin);
    int n,d,ans=1;
    cin>>d>>n;
    for(int i=0;i<d;i++)
        ans*=100;
    cout<<(n!=100?n*ans:101*ans);
    return 0;
}
