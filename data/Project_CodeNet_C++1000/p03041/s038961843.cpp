#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    string s,ans="";
    cin>>n>>k>>s;
    for(int i=0;i<n;i++)
    {
        if(k==i+1)
        {
            if(s[i]=='A')
                ans +='a';
            if(s[i]=='B')
                ans +='b';
                if(s[i]=='C')
                ans +='c';
        }
        else
        {
            ans +=s[i];
        }
    }
    cout<<ans<<endl;
}
