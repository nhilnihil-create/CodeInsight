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
    int ans=0;
    string s;
    cin>>s;
    for(int i=0;i<4;i++)
        ans+=(s[i]=='+'?1:-1);
    cout<<ans;
    return 0;
}
