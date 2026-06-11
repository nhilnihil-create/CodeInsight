#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)


int main()
{
    optimize();

    int n;
    cin>> n;

    int c[n], v[n], r=0;

    for(int i=0; i<n; i++)
        cin>> c[i];


     for(int i=0; i<n; i++)
    {
        cin>> v[i];
        if(c[i]> v[i])
            r+=(c[i]- v[i]);

    }

    cout<< r;
    nl;

    return 0;
}

