#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans=-1,l;    
    string s,s1,s2;
    cin>>l>>s;

    for(int i=1;i<l;i++)
    {
        int cnt=0;
        s1=s.substr(0,i);
        s2=s.substr(i,l-1);
        //cout<<s1<<" "<<s2<<endl;
        set<char>x,y;
        for(int i=0;i<s1.length();i++)
            x.insert(s1[i]);
        for(int i=0;i<s2.length();i++)
            y.insert(s2[i]);
        for(auto c: x)
        {
            cnt+=y.count(c);               //return 1 or 0 only
        }
        if(cnt>ans)
            ans=cnt;
    }
    cout<<ans<<endl;
    return 0;
}
