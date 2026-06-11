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

    int n, m, x, y;
    cin>> n>> m>> x>> y;

    int x1[n+1], y1[m+1];

    for(int i= 0; i<n; i++)
        cin>> x1[i];
    x1[n]= x;


    for(int i= 0; i<m; i++)
        cin>> y1[i];
    y1[m]= y;

    sort (x1, x1+n+1);
    sort (y1, y1+m+1);


    cout << (y1[0] -x1[n] > 0 ? "No War\n" :"War\n" );

    return 0;
}


