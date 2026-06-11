#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;

const int N=1e7;

ll v[N+10];

ll a[N+10];


bool compare(string  &a, string &b)
{
     string f=a+b,c=b+a;

     return f<c;
}

int main()
{
    ll a,b,c,sum=0;

    cin>>a>>b>>c;

    vector<ll>v;

    for(ll i=1;i<=10;i++)
    {
    sum=(a*c)-b;
    v.push_back(sum);
    c=sum;
    }
    for(auto i:v)
    {
        cout<<i<<endl;
    }



}






