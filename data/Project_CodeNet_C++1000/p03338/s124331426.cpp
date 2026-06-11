#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    vector<int> right(26,0),left(26,0);
    for(int i=0;i<str.size();i++)
    {
        left[str[i]-'a']++;
    }
    int ans=0;
    for(int i=0;i<str.size();i++)
    {
       right[str[i]-'a']++;
       left[str[i]-'a']--;
       int c=0;
       for(int j=0;j<26;j++)
       {
           if(right[j] && left[j])
           c++;
       }
       ans=max(ans,c);
    }
    cout<<ans<<endl;


}