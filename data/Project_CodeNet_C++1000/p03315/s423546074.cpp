#include<bits/stdc++.h>
using namespace std;
#define int long long 
main()
{
    string s;
    cin>>s;
    int n=s.size(),ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='-') ans--;
        else ans++;
    }
    cout<<ans<<endl;
}
