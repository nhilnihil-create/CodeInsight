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

    string s[n];
    double d[n], ans=0;


    for(int i=0; i<n; i++)
    {
        cin>> d[i]>> s[i];

        if(s[i]=="JPY")
        ans+=d[i];
        else
            ans+=((d[i]* 380000));

    }

   // cout<< fixed<< setprecision<< 5;
    cout<< ans<< endl;


    return 0;
}


