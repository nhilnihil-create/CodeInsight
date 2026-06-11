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

    int n, t, c, ti;

    cin>> n>> t;

    vector < pair <int, int> > v(n);

    for(int i=0; i<n; i++)
    {
        cin>>  c>> ti;
        v[i].first= c;
        v[i].second= ti;
    }


    sort (v.begin(), v.end ());

    for(int i=0; i<n; i++)
    {
        if( v[i].second<= t)
        {
            cout << v[i].first;
            return 0;
        }
    }

    cout << "TLE\n";


    return 0;
}