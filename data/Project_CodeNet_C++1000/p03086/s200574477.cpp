#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int ans =0;
    int temp=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T')
        {
            temp++;
            if(i==s.size()-1)
            {
            cout<<max(ans,temp)<<"\n";
            return 0;
            }
        }
        else
        {
            ans=max(ans,temp);
            temp=0;
        }
    }
    cout<<ans<<"\n";
    
}