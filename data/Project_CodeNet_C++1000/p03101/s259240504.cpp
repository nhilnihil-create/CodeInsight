#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;
int h,w;
int a,b;
int main()
{
   cin>>a>>b>>h>>w;
    int ans=0;
    ans=a*b-h*b-w*a+h*w;
    cout<<ans;
    return 0;
}
