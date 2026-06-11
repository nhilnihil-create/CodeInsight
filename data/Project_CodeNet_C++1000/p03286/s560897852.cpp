#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    ll n;
    cin>>n;
    if (n==0)
        cout<<"0\n";
    else
    {
        string s="";
        while (n)
        {
            if (n%2==1 || n%2==-1)
            {
                n--;
                s+='1';
            }
            else
                s+='0';
            n/=-2;
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
}