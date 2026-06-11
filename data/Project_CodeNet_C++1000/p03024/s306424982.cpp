#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string n;
    cin>>n;
    ll cnt=0,other;
    for(int i=0;i<n.length();i++)
    {
        if(n[i]=='x')
            cnt++;
        else
            other++;
    }
    if(cnt<=7)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;

    return 0;
}
