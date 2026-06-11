#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define sq(x)           ((x)*(x))
#define pi              acos(-1.0)
#define NUM             1000005

typedef long long ll;


int main()
{
    FastRead

    string s;
    ll cnt1=0,cnt2=0;
    
    cin>>s;
    
    for(ll i=0; i<s.size(); i++)
    {
        if(i%2==0 && s[i]=='0')
        {
            cnt1++;
        }
        if(i%2==1 && s[i]=='1')
        {
            cnt1++;
        }
    }
    
    for(ll i=0; i<s.size(); i++)
    {
        if(i%2==1 && s[i]=='0')
        {
            cnt2++;
        }
        if(i%2==0 && s[i]=='1')
        {
            cnt2++;
        }
    }
    
    cout<<min(cnt1,cnt2)<<endl;
}
