#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long 
#define F(n) for(int i = 0; i < n; ++i)
#define Debug cout<<endl<<"I AM IRONMAN"<<endl

int main ()
{
    fastio;
    string a;
    cin >> a;
    int p1=0,p2=0;
    for(int i=0;i<a.length();i++)
    {
        if(i%2==0 && a[i]=='0')
        {
            p1++;
        }
        if(i%2==1 && a[i]=='1')
        {
            p1++;
        }
        
    }
    for(int i=0;i<a.length();i++)
    {
        if(i%2==0 && a[i]=='1')
        {
            p2++;
        }
        if(i%2==1 && a[i]=='0')
        {
            p2++;
        }
        
    }
    cout << min(p1,p2);
    return 0;
}