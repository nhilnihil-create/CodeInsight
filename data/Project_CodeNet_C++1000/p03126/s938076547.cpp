
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
   // tt
    {
        int n, m;
        cin>> n>> m;

        int f[m]={}, k, r, c=0;

        for(int i= 0; i<n; i++)
        {
            cin>> k;
            for(int p=0; p<k; p++)
            {
                cin>> r;
                f[r-1]++;
            }

        }

        for(int i=0; i<m; i++)
        {
            if(f[i]== n)
                c++;
        }

        cout<< c;
        nl;
    }

    return 0;
}

