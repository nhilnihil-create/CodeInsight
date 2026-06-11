#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;

    set<ll>s;
    //s.insert(n);
    while(s.count(n)==0)
    {
        s.insert(n);
        if(n&1)
        {
           n=3*n+1;
        }
        else{
            n=n/2;
        }
    }
    cout<<s.size()+1<<endl;
}

