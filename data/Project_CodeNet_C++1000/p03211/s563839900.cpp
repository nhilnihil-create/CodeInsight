#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin>>s;
    int ans=INT_MAX;
    for(int i=0;i<=s.size()-3;i++){
        int x=0;
        x+=s[i]-'0';
        x*=10;
        x+=s[i+1]-'0';
        x*=10;
        x+=s[i+2]-'0';
        ans=min(ans,abs(x-753));
    }
        cout<<ans;
    return 0;
}
