//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,r,j;
    string s,t;
    cin>>r;
    if (r < 1200)
        cout << "ABC";
    else if (r >= 1200 && r < 2800)
        cout << "ARC";
    else
        cout << "AGC";
    return 0;
}



