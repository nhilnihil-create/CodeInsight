#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,j,k,l,a,b,c,d;
    string s1;
    cin>>n;
    if(n==0){s1.push_back('0');}
    while(n!=0)
    {
        if(n%-2!=0)
        {
            s1.push_back('1');
            n--;

        }
        else
        {
            s1.push_back('0');
        }
        n=n/(-2);
       // cout<<n<<endl;
    }
    reverse(s1.begin(),s1.end());
    cout<<s1<<endl;
}
