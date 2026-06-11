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

    int n, m, t;
    cin>> n>> m;

    int f[m+1]= {}, k[n];

    for(int i=0; i<n; i++)
    {
        cin>> k[i];
        while (k[i]--)
        {
            cin>> t;
            f[t]++;
        }
    }

    sort (f, f+m+1, greater <int> ());

    int i=0;
    while ( f[i] ==n)
        i++;

    cout << i;
    nl;


    return 0;
}


