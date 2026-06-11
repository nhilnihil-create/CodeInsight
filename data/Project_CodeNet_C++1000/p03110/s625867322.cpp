#include<bits/stdc++.h>
using namespace std;
int n;
double x,ans;
string s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>s;
        if(s=="JPY")ans+=x;
        else ans+=x*380000;
    }
    printf("%.6f",ans);
    return 0;
}