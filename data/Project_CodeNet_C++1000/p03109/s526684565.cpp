#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const ll mx=1e7;

int main()
{
    optimize();

    string s;
    ll d[2]= {}, t=mx;
    d[0]=20190430;
    cin>> s;

    for(int i=0; i<10; i++)
    {
        if(i!=4 && i!=7)
        {
            d[1]+=((s[i]-'0')* t);
            t/=10;
        }
    }

    if(d[1]> d[0])
        cout<< "TBD\n";

    else
        cout<< "Heisei\n";

    return 0;
}


