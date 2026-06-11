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


    int x1, x2, y1, y2;

    cin>>  x1>> y1>> x2>> y2;

    int dx= x2-x1, dy= y1- y2;

    cout << x2+ dy <<' ' << y2 + dx<< ' ' << x1+ dy<< ' '<< y1+ dx;
    nl;

    return 0;
}

