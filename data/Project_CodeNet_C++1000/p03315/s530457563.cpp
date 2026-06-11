#include<bits/stdc++.h>
#define     fast                    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     ll                      long long
#define     pb                      push_back
#define     M                       1000000007
using namespace std;
int main()
{
    ll n,x,y,sum=0;
    string s;
    cin>>s;
    for(ll i=0; i<s.size(); i++)
    {
        if(s[i] == '+') sum++;
        else sum--;
    }
     cout<<sum<<endl;


}
