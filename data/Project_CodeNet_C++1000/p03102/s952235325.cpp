#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tt int t; cin>>t; while(t--)
#define nl cout<<"\n";
#define sp cout<<" ";
#define rep(i, a, b) for(long long i=a; i<b; i++)

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
double PI = 4*atan(1);

int main()
{
    optimize();
    int code= 0,  n, m, c;

    cin>> n>> m>> c;

    int b[m], t, sum= 0;
    for(int i=0; i<m; i++)
        cin>> b[i];

    for(int i=0; i<n; i++)
    {
        sum =0;
        for(int i=0; i<m; i++)
        {
            cin>> t;
            sum+= (b[i]*t);
        }

        if( sum +c >0)
            code++;
    }

    cout << code ;
    nl;

    return 0;
}


