#include <bits/stdc++.h>
#include <cstring>
#include <ctype.h>
#include<stdlib.h>

#define flin            freopen("input.txt", "r", stdin); 
#define flout           freopen("output.txt", "w", stdout);
#define ll              long long
#define ull             unsigned long long
#define fastio          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define nl              '\n'
#define nll             '\0'
#define pb              push_back
#define bdyptb          return 0;
#define sorted(x)       sort(x.begin(), x.end())
#define reversed(x)     reverse(x.begin(), x.end())
#define all(x)          x.begin(), x.end()
#define mset(a, b)      memset(a, b, sizeof(a));
#define testcase        ll t,tt; cin>>tt; for(t=1;t<=tt;t++)

#define pi acos(-1.00)   
#define mx 1000007

using namespace std;

int main()
{
    
    string a; 
    cin>>a;
    ll c=0, len=a.size(); 
    vector<int> vc(len);
    for (int  i= 0 ; i < len; i++)
    {
        if (a[i]=='B')
        c++;
        vc[i]=c;
    }
    ll ans=0;
    for(int i=len-1; i>0; i--)
    {
        if(a[i]=='W')
        ans+=vc[i];
    }
    cout<<ans<<nl;
}